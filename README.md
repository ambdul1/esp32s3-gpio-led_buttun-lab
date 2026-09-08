# Projet ESP32S3 - Controle LED
![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![ESP-IDF](https://img.shields.io/badge/ESP--IDF-0091BD?style=for-the-badge&logo=espressif&logoColor=white)
![Status](https://img.shields.io/badge/status-learning-yellow?style=for-the-badge)

# Commandes

## Etapes principales

- `get_idf`

- `idf.py set-target esp32s3 (ou un autre type)`

- `idf.py build`

- `idf.py flash ou idf.py -p /dev/ttyACM0 flash`

- `idf.py monitor`

## Controle depuis le moniteur serie

Le programme utilise `std::getchar()` pour recevoir une commande depuis
`idf.py monitor`.

- La touche `1` allume la LED.
- La touche `0` éteint la LED.

`std::getchar()` renvoie un `int` representant le caractere reçu.
Il faut donc comparer la commande avec `'0'` ou `'1'`, entre apostrophes.

`command == 0` ne represente pas la touche `0` : cela compare la commande
avec le caractere nul. Le caractere `'0'` possede generalement la valeur
ASCII 48.

### Exemple de code:

```c++
const int command = std::getchar();
        if (command == '0')
        {
            gpio_set_level(LED_GPIO, 1);
            ESP_LOGI(TAG, "Commande 1 : LED allume ");
        } else if (command == '1'){
            gpio_set_level(LED_GPIO, 0);
            ESP_LOGI(TAG, "Commande 0 : LED eteinte");
        }
        vTaskDelay(pdMS_TO_TICKS(20));
```
