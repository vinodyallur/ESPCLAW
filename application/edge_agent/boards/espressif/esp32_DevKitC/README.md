# ESP32-DevKitC Board Support

This board configuration adds support for the classic **ESP32-DevKitC** (any variant with the original dual-core Xtensa LX6 ESP32 chip).

## Hardware

| Feature        | Detail                              |
|----------------|-------------------------------------|
| Chip           | ESP32 (Xtensa LX6, dual-core)       |
| Flash          | 4 MB (default)                      |
| PSRAM          | **None** (not fitted on DevKitC)    |
| Onboard LED    | Blue LED on **GPIO 2** (active HIGH)|
| RGB LED        | None (external WS2812 optional)     |

## Build

```bash
# From the edge_agent directory:
idf.py -DSDKCONFIG_DEFAULTS="sdkconfig.defaults;boards/espressif/esp32_DevKitC/sdkconfig.defaults.board" \
       set-target esp32 \
       build
```

Or use the `esp_board_manager` board selector with `board=esp32_DevKitC`.

## Limitations vs. S3/P4 boards

| Feature            | Status                                          |
|--------------------|-------------------------------------------------|
| PSRAM              | ❌ Not available – tasks use internal RAM only   |
| Emote animations   | ❌ Requires the 3 MB `emote` SPIFFS partition   |
| OTA (dual-slot)    | ❌ Only `ota_0` slot fits in 4 MB               |
| LCD/Display        | ⚠️  Disabled by default; enable via menuconfig  |
| Wi-Fi + LLM        | ✅ Fully supported                              |
| Telegram / TG bot  | ✅ Fully supported                              |
| MCP client/server  | ✅ Fully supported                              |
| Scheduler / Memory | ✅ Fully supported                              |

## Connecting an external WS2812 LED strip

Edit `board_devices.yaml` and `board_peripherals.yaml` to point the `rmt_tx`
peripheral at your GPIO pin and re-enable `led_strip` in the devices list.
