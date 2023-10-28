#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define LED_PIN GPIO_NUM_16

void blink(int on_time, int off_time, int repeats) {
    for (int i = 0; i < repeats; i++) {
        gpio_set_level(LED_PIN, 1); 
        vTaskDelay(on_time / portTICK_PERIOD_MS);
        gpio_set_level(LED_PIN, 0); 
        vTaskDelay(off_time / portTICK_PERIOD_MS);
    }
}

void app_main() {
    gpio_pad_select_gpio(LED_PIN);
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);

    while (1) {
        // Blink pattern: ON for 1s, OFF for 1s, repeat 3 times
        blink(1000, 1000, 3);

        blink(200, 200, 5);

        blink(300, 100, 4);

      
    }
}
