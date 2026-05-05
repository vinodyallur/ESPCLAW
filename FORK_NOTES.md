# Fork Notes

This repository is a fork of [ESP-Claw](https://github.com/espressif/esp-claw)
by Espressif Systems (Shanghai) CO LTD, licensed under Apache 2.0.

## What changed in this fork

| File / Folder | Change |
|---|---|
| `application/edge_agent/boards/espressif/esp32_DevKitC/` | **New** — Classic ESP32-DevKitC board config (no PSRAM, 4 MB flash) |
| `application/edge_agent/boards/espressif/esp32c3_DevKitM/` | **New** — ESP32-C3-DevKitM-1 board config (RISC-V, no PSRAM, 4 MB flash) |
| `application/edge_agent/partitions_4MB.csv` | **New** — Partition table for 4 MB flash boards |
| `application/edge_agent/sdkconfig.defaults` | **Modified** — Added comments; SPIRAM options now clearly marked as board-specific defaults |
| `README.md` | **Modified** — Fork banner + new board documentation section |
| `CHANGELOG.md` | **Modified** — Added entry for this fork's changes |

## Upstream

Original project: https://github.com/espressif/esp-claw  
Original license: Apache 2.0 (see `LICENSE`)

All original copyright headers are preserved as required by the license.
