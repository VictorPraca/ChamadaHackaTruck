#include <SPI.h>
#include <MFRC522.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

// NFC
#define RST_PIN D1
#define SS_PIN  D2
MFRC522 mfrc522(SS_PIN, RST_PIN);

// LEDs e buzzer
#define LED_BRANCO D3
#define LED_VERDE D4
#define LED_VERMELHO D0
#define BUZZER_PIN D8

// Wi-Fi
const char *WIFI_SSID = "HackaTruckIoT";
const char *WIFI_PASSWORD = "iothacka";
const char *URL = "http://192.168.128.90:1880/PostP";

// UID válidos
String validUIDs[] = {"C3A1AD2B", "A1B2C3D4", "82BFAD"};

// Fila de envio offline
struct RegistroPendente {
  String uid;
  String data;
};
RegistroPendente filaPendentes[100]; // Agora até 100 registros
int filaCount = 0;

// WiFi/NTP
WiFiClient client;
HTTPClient httpClient;
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", -10800, 60000); // UTC-3

void setup() {
  Serial.begin(115200);
  SPI.begin();
  mfrc522.PCD_Init();

  pinMode(LED_BRANCO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(LED_BRANCO, HIGH);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Conectando ao WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi conectado!");

  timeClient.begin();
  timeClient.update();

  Serial.println("Sistema pronto. Aproxime um cartão...");
}

void loop() {
  timeClient.update();
  enviarPendentesSePossivel();

  if (!mfrc522.PICC_IsNewCardPresent()) return;
  if (!mfrc522.PICC_ReadCardSerial()) return;

  String uid = "";
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    uid += String(mfrc522.uid.uidByte[i], HEX);
  }
  uid.toUpperCase();
  Serial.println("UID detectado: " + uid);

  // Data atual formatada
  time_t rawTime = timeClient.getEpochTime();
  struct tm *timeInfo = localtime(&rawTime);
  char dataFormatada[11];
  sprintf(dataFormatada, "%02d/%02d/%04d", timeInfo->tm_mday, timeInfo->tm_mon + 1, timeInfo->tm_year + 1900);
  String dataAtual = String(dataFormatada);

  if (!autorizado(uid)) {
    feedbackNegado();
    return;
  }

  feedbackAutorizado();

  if (WiFi.status() == WL_CONNECTED) {
    enviarParaServidor(uid, dataAtual);
  } else {
    armazenarPendente(uid, dataAtual);
  }

  mfrc522.PICC_HaltA();
  delay(2000);
}

bool autorizado(String uid) {
  for (String id : validUIDs) {
    if (uid == id) return true;
  }
  return false;
}

void armazenarPendente(String uid, String datap) {
  if (filaCount < 100) {
    filaPendentes[filaCount++] = { uid, datap };
    Serial.println("Conexão perdida. Registro armazenado na fila.");
  } else {
    Serial.println("Fila de pendentes cheia. Registro descartado.");
  }
}

void enviarPendentesSePossivel() {
  if (WiFi.status() != WL_CONNECTED || filaCount == 0) return;

  Serial.println("Enviando registros pendentes...");
  for (int i = 0; i < filaCount; i++) {
    enviarParaServidor(filaPendentes[i].uid, filaPendentes[i].data);
    delay(500);
  }
  filaCount = 0;
}

void enviarParaServidor(String uid, String datap) {
  httpClient.begin(client, URL);
  httpClient.addHeader("Content-Type", "application/json");

  String json = "{\"matricula\":\"" + uid + "\",\"datap\":\"" + datap + "\",\"idDisc\":12345}";
  int httpResponseCode = httpClient.POST(json);

  Serial.println("Enviando para API:");
  Serial.println(json);
  Serial.print("Resposta: ");
  Serial.println(httpResponseCode);

  httpClient.end();
}

void feedbackAutorizado() {
  Serial.println("Cartão autorizado");

  digitalWrite(LED_BRANCO, LOW);
  digitalWrite(LED_VERDE, HIGH);

  tone(BUZZER_PIN, 1500, 300);
  delay(400);
  tone(BUZZER_PIN, 1800, 300);
  delay(1000);

  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_BRANCO, HIGH);
}

void feedbackNegado() {
  Serial.println("Cartão NÃO autorizado");

  digitalWrite(LED_BRANCO, LOW);
  digitalWrite(LED_VERMELHO, HIGH);

  for (int i = 0; i < 3; i++) {
    tone(BUZZER_PIN, 500, 200);
    delay(300);
  }

  delay(1000);
  digitalWrite(LED_VERMELHO, LOW);
  digitalWrite(LED_BRANCO, HIGH);
}
