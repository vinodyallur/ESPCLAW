/*
 * SPDX-FileCopyrightText: 2026 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file setup_device.c
 * @brief Board-level device initialisation for ESP32-DevKitC (classic ESP32).
 *
 * The classic ESP32-DevKitC has:
 *   - B blue LED on GPIO 2 (active high).
 *   - No onboard WS2812 RGB strip.
 *   - No PSRAM.
 *
 * If you have an external WS2812 strip connected to a GPIO, add an
 * led_strip device in board_devices.yaml / board_peripherals.yaml and
 * initialise it here following the ESP32-S3-DevKitC-1 example.
 */

#include <string.h>
#include "esp_log.h"
#include "esp_check.h"
#include "esp_board_manager_includes.h"

static const char *TAG = "board_esp32_devkitc";

/* The blue user LED sits on GPIO 2 on most ESP32-DevKitC variants. */
#define BOARD_LED_GPIO 2

esp_err_t setup_board_devices(void)
{
    /* Configure the onboard blue LED as a simple GPIO output. */
    gpio_config_t io_conf = {
        .pin_bit_mask = (1ULL << BOARD_LED_GPIO),
        .mode         = GPIO_MODE_OUTPUT,
        .pull_up_en   = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type    = GPIO_INTR_DISABLE,
    };
    esp_err_t ret = gpio_config(&io_conf);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Failed to configure LED GPIO: %s", esp_err_to_name(ret));
        return ret;
    }

    /* Start with the LED off. */
    gpio_set_level(BOARD_LED_GPIO, 0);
    ESP_LOGI(TAG, "ESP32-DevKitC board initialised (LED on GPIO %d)", BOARD_LED_GPIO);
    return ESP_OK;
}
