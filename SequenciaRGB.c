#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h" 

const uint led_pin_blue = 11;
const uint led_pin_red  = 12;
const uint led_pin_green  = 13;
const uint BUTTON_PIN = 5;

uint8_t led_atual = 1;
bool all_led_active = false;

int64_t turn_off_callback(alarm_id_t id, void *user_data) {

    switch (led_atual)
    {
    case 1:
        gpio_put(led_pin_red, false);
        gpio_put(led_pin_blue, true);
        gpio_put(led_pin_green, true);
        led_atual++;
        add_alarm_in_ms(3000, turn_off_callback, NULL, false);
        break;
    case 2:
        gpio_put(led_pin_red, false);
        gpio_put(led_pin_blue, false);
        gpio_put(led_pin_green, true);
        led_atual++;
        add_alarm_in_ms(3000, turn_off_callback, NULL, false);
        break;
    case 3:
        gpio_put(led_pin_red, false);
        gpio_put(led_pin_blue, false);
        gpio_put(led_pin_green, false);
        led_atual = 1;
        all_led_active = false;
        break;
    
    default:
        printf("Erro na execucao");
        break;
    }

    return false;        //true mantem o temporizador repetindo. se for false ele para
}

int main()
{
    stdio_init_all();

    gpio_init(led_pin_red);
    gpio_set_dir(led_pin_red, GPIO_OUT);
    gpio_init(led_pin_blue);
    gpio_set_dir(led_pin_blue, GPIO_OUT);
    gpio_init(led_pin_green);
    gpio_set_dir(led_pin_green, GPIO_OUT);
    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);

    gpio_pull_up(BUTTON_PIN);

    while (true) {
        if (gpio_get(BUTTON_PIN) == 0 && !all_led_active) {
            // Adiciona um pequeno atraso para debounce, evitando leituras errôneas.
            sleep_ms(50);

            // Verifica novamente o estado do botão após o debounce.
            if (gpio_get(BUTTON_PIN) == 0) {

                gpio_put(led_pin_red, true);
                gpio_put(led_pin_blue, true);
                gpio_put(led_pin_green, true);
                all_led_active = true;

                // Agenda um alarme para desligar o LED após 3 segundos (3000 ms).
                // A função 'turn_off_callback' será chamada após esse tempo.
                add_alarm_in_ms(3000, turn_off_callback, NULL, false);
            }
        }
         sleep_ms(10);  // Reduz uso excessivo da CPU
    }

        return 0;
}
