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
![Leitor NFC RC522](https://upload.wikimedia.org/wikipedia/commons/thumb/0/00/RFID-RC522.jpg/320px-RFID-RC522.jpg)

### NodeMCU ESP8266
![NodeMCU](https://upload.wikimedia.org/wikipedia/commons/thumb/f/f1/NodeMCU_DEVKIT_1.0.jpg/320px-NodeMCU_DEVKIT_1.0.jpg)

### LEDs e Buzzer
![LEDs e Buzzer](https://upload.wikimedia.org/wikipedia/commons/9/99/Buzzer_and_LEDs.jpg)

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
