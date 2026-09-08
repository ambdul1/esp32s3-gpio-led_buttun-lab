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

## Exemple d utilisation 

**_On peut ajouter dans la boucle `getchar` pour prendre une entree comme `0` ou `1`, allumer la led ou l eteindre.  
NB: commande == 0 est faux, `getchar` prend uniquement des caracteres._**
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
