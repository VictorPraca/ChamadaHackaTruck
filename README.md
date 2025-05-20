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

## 🖼️ Componentes

### Leitor NFC RC522
![Leitor NFC RC522] (https://app.cirkitdesigner.com/project/f4564a5b-4ae4-4b1f-8a08-e86be5e817d3)

### NodeMCU ESP8266
![NodeMCU](https://app.cirkitdesigner.com/project/44e59bfc-7859-4ab4-8ed2-739a47d4f0fd)

---

## Circuito Completo
(https://app.cirkitdesigner.com/project/350f5c02-84ec-4470-85c4-f96aefac15a8)

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
