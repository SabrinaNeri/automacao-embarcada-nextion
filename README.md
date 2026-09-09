# 🤖 Sistema Embarcado de Automação com Arduino e Display Nextion

Este repositório contém o código-fonte de um sistema embarcado desenvolvido na plataforma **Arduino (linguagem C/C++)**. O projeto implementa o controle integrado de múltiplos atuadores físicos por meio de uma interface gráfica de usuário (GUI) touchscreen, com comunicação estabelecida via protocolo Serial.

---

## 🛠️ Recursos Técnicos Implementados

* **Interface IHM (Nextion):** Gerenciamento e escuta de eventos por toque (`NexTouch`), incluindo botões de estado duplo (Dual-state) e sliders de controle numérico.
* **Controle Dinâmico de Motores CC (Ponte H):** Modulação por Largura de Pulso (**PWM**) para variação suave de velocidade, integrada a uma função personalizada de controle de direção.
* **Modulação de Cargas de Potência:** Acionamento temporizado de módulo Relé (isolamento galvânico para controle de iluminação/lâmpadas).
* **Controle Angular Simulado:** Varredura milimétrica de posicionamento utilizando servomotor.
