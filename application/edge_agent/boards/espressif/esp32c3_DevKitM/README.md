# ESP32-C3-DevKitM-1 Board Support

This board configuration adds support for the **ESP32-C3-DevKitM-1** — the
compact RISC-V single-core development board from Espressif.

## Hardware

| Feature        | Detail                                        |
|----------------|-----------------------------------------------|
| Chip           | ESP32-C3 (RISC-V, single-core, 160 MHz max)  |
| Flash          | 4 MB                                          |
| PSRAM          | **None**                                      |
| Onboard LED    | WS2812 RGB LED on **GPIO 8** (via RMT)        |

## Build

```bash
# From the edge_agent directory:
idf.py -DSDKCONFIG_DEFAULTS="sdkconfig.defaults;boards/espressif/esp32c3_DevKitM/sdkconfig.defaults.board" \
       set-target esp32c3 \
       build
```

Or use the `esp_board_manager` board selector with `board=esp32c3_DevKitM`.

## Limitations vs. S3/P4 boards

| Feature            | Status                                          |
|--------------------|-------------------------------------------------|
| PSRAM              | ❌ Not available                                 |
| Emote animations   | ❌ Requires ~3 MB SPIFFS – too large for 4 MB   |
| OTA (dual-slot)    | ❌ Only `ota_0` fits                             |
| Core pinning       | ⚠️  Single core; `tskNO_AFFINITY` used throughout|
| LCD/Display        | ⚠️  Disabled by default                          |
| Wi-Fi + LLM        | ✅ Fully supported                              |
| Telegram / TG bot  | ✅ Fully supported                              |
| MCP client/server  | ✅ Fully supported                              |
| Scheduler / Memory | ✅ Fully supported                              |

## Notes

- The ESP32-C3 **RMT peripheral does not support DMA** — `with_dma` is set to
  `false` in `board_peripherals.yaml`.
- `MBEDTLS_EXTERNAL_MEM_ALLOC` is disabled (no PSRAM to allocate into).
- The C3's ~400 KB of internal DRAM is sufficient for the core CLAW agent loop,
  Wi-Fi, TLS, and basic capabilities.
