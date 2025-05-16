# 🎒 Sistema de Controle de Acesso Escolar com NFC

Este projeto simula um sistema de controle de entrada e saída de alunos em salas de aula, utilizando **NodeMCU ESP8266**, **leitor NFC** e sinalização com **LEDs** e **buzzer**.

---

## 👨‍💻 Alunos responsáveis:

- Bruno Lucas Caixeta Braga
- Efraim de Jesus Farias Costa
- Felipe Gaudereto de Freitas Mello
- Victor Alexandre Praça Maciel

---

## 🔧 Componentes de Hardware Utilizados

| Componente        | Função                                                         |
|-------------------|----------------------------------------------------------------|
| NodeMCU ESP8266   | Microcontrolador para controle do sistema                      |
| Módulo RC522 NFC  | Leitor dos cartões RFID/NFC                                    |
| LED Branco        | Indica que o sistema está ligado e em funcionamento            |
| LED Verde         | Indica acesso autorizado (entrada válida)                      |
| LED Vermelho      | Indica acesso negado (cartão inválido)                         |
| Buzzer            | Emite sons diferentes para autorizado e não autorizado         |
| Protoboard        | Montagem do circuito sem solda                                 |
| Jumpers           | Cabos de conexão                                               |

---

## 🖼️ Fotos dos Componentes

### Leitor NFC RC522
![Leitor NFC RC522] (https://images.tcdn.com.br/img/img_prod/672486/sensor_rfid_mfrc522_13_56_mhz_75_1_bc1ba82d22bd543cf061c9d484c295bd_20241128103827.jpg)

### NodeMCU ESP8266
![NodeMCU](https://i0.wp.com/multipecascuritiba.com.br/wp-content/uploads/2023/05/placa-de-desenvolvimento-nodemcu-lua-wifi-com-esp8266-esp-12e-v3-0_4400.jpg?fit=1024%2C1024&ssl=1)

---

## ⚙️ Funcionamento do Projeto

1. Aluno aproxima o cartão NFC do leitor.
2. O sistema identifica o UID do cartão.
3. Se o UID for autorizado:
   - Acende LED verde.
   - Toca melodia de dois tons no buzzer.
4. Se o UID não for reconhecido:
   - Acende LED vermelho.
   - Emite 3 bipes curtos e graves no buzzer.
5. O LED branco permanece ligado indicando o sistema em operação.

---
