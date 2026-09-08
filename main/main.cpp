#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/gpio.h>
#include <esp_err.h>
#include <esp_log.h>

namespace 
{
    constexpr char TAG[] = "GPIO_LED_BUTTON";
    constexpr gpio_num_t LED_GPIO = GPIO_NUM_7;
    constexpr gpio_num_t BUTTON_GPIO = GPIO_NUM_8;
}

extern "C" void app_main()
{
    gpio_config_t led_config{};

    led_config.pin_bit_mask = 1ULL << LED_GPIO;
    led_config.mode = GPIO_MODE_OUTPUT;
    led_config.pull_up_en = GPIO_PULLUP_DISABLE;
    led_config.pull_down_en = GPIO_PULLDOWN_DISABLE;
    led_config.intr_type = GPIO_INTR_DISABLE;

    gpio_config_t button_config{};

    button_config.pin_bit_mask = 1ULL << BUTTON_GPIO;
    button_config.mode = GPIO_MODE_INPUT;
    button_config.pull_up_en = GPIO_PULLUP_ENABLE;
    button_config.pull_down_en = GPIO_PULLDOWN_DISABLE;
    button_config.intr_type = GPIO_INTR_DISABLE;

    const esp_err_t led_result = gpio_config(&led_config);
    const esp_err_t button_result = gpio_config(&button_config);

    if (button_result != ESP_OK)
    {
        ESP_LOGE(
                TAG,
                "Echec de la configuration du bouton su le GPIO 8 : %s",
                esp_err_to_name(button_result));
        return;
    }

    else if (led_result != ESP_OK)
    {
        ESP_LOGE(
                TAG,
                "Echec de la configuration de la led sur le GPIO 7 : %s",
                esp_err_to_name(led_result));
        return;
    }
    
    const esp_err_t led_set_result = gpio_set_level(LED_GPIO, 0);

    if (led_set_result != ESP_OK)
    {
        ESP_LOGE(
                TAG,
                "Echec de l initialisation du LED a l etat le plus bas (LOW) %s",
                esp_err_to_name(led_set_result)
                );
        return;
    }


    for (;;)
    {
        const int get_button = gpio_get_level(BUTTON_GPIO);
        //ESP_LOGI(TAG, "Bouton : %d ", get_button);
        //vTaskDelay(pdMS_TO_TICKS(500));
    
        if (get_button == 0)
        {
            gpio_set_level(LED_GPIO, 1);
            //ESP_LOGI(TAG, "Allume : %d ", get_button);
        } else {
            gpio_set_level(LED_GPIO, 0);
            //ESP_LOGI(TAG, "Eteint : %d", get_button);
        }

        vTaskDelay(pdMS_TO_TICKS(20));
    }

}
