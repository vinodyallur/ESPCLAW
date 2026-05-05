/*
 * SPDX-FileCopyrightText: 2026 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file setup_device.c
 * @brief Board-level device initialisation for ESP32-C3-DevKitM-1.
 *
 * The ESP32-C3-DevKitM-1 has:
 *   - A WS2812 RGB LED on GPIO 8 (driven via RMT).
 *   - No PSRAM.
 *   - Single RISC-V core (no core-affinity pinning).
 *
 * The led_strip device is declared in board_devices.yaml and wired to the
 * rmt_tx peripheral in board_peripherals.yaml (GPIO 8, DMA disabled).
 */

#include <string.h>
#include "esp_log.h"
#include "esp_check.h"
#include "esp_board_manager_includes.h"
#include "gen_board_device_custom.h"
#include "periph_rmt.h"
#include "led_strip.h"
#include "led_strip_rmt.h"
#include "led_strip_types.h"

static const char *TAG = "board_esp32c3_devkitm";

esp_err_t setup_board_devices(void)
{
    ESP_LOGI(TAG, "ESP32-C3-DevKitM-1 board initialised");
    ESP_LOGI(TAG, "WS2812 RGB LED declared on GPIO 8 via RMT (no DMA)");
    return ESP_OK;
}
