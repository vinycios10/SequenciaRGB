# Controle de LEDs com Botão no Raspberry Pi Pico

Este projeto acende e apaga LEDs no Raspberry Pi Pico ao pressionar um botão.

## Componentes Utilizados

- Raspberry Pi Pico
- 3 LEDs (azul, vermelho e verde)
- 1 botão
- Resistores adequados para LEDs e botão
- Fios de conexão

## Funcionamento

1. O sistema inicia com os LEDs apagados.
2. Ao pressionar o botão, todos os LEDs acendem e um temporizador de 3 segundos é acionado.
3. Após os 3 segundos, os LEDs desligam um por um, seguindo a sequência programada.
4. O sistema aguarda uma nova interação.

## Como Usar

1. Monte o circuito conectando:
   - **LED azul:** GPIO 11
   - **LED vermelho:** GPIO 12
   - **LED verde:** GPIO 13
   - **Botão:** GPIO 5
2. Compile e carregue o código no Raspberry Pi Pico.
3. Pressione o botão para acionar os LEDs.

## Bibliotecas Utilizadas

- `pico/stdlib.h` - Funções básicas do Pico.
- `pico/time.h` - Controle de temporização.

## Código

O código-fonte está disponível no arquivo `SequenciaRGB.c`.
