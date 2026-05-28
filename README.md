# Retro-Pad
What happens if a keyboard can emulate Retro Stuff?
Yah its just a simple keyboard but include a 4inch tft and speaker for Retro Emulation and Designed for myself.

## Tinkercad Link
https://www.tinkercad.com/things/bjJYySNUwrn-blekeyboard-esp32?sharecode=VCYoCMCinC_T4FhX9W5qrWKZ11Hd7W0aXTLVOQ6IZxw
## Zine Page Design
https://www.figma.com/design/CGgY6SRriEGCdJu8L95h5M/Retro-Pad-Zine-Page?node-id=0-1&t=7zGqFnisPlWxRSIn-1
## Images
![Design](https://github.com/12zcab/Retro-Pad/raw/refs/heads/main/img/Design.png)
![PCB_F](https://github.com/12zcab/Retro-Pad/raw/refs/heads/main/img/PCB_F.png)
![PCB_B](https://github.com/12zcab/Retro-Pad/raw/refs/heads/main/img/PCB_B.png)
![Routing](https://github.com/12zcab/Retro-Pad/raw/refs/heads/main/img/Routing.png)

## Notes
Erm the Emulator Part is not yet programmed as i haven't build it irl yet
I will work on it as I receive the grant to buy the ESP32
Also as i like Looking at PCBs so the case will be really simple

## Why I build this?
1.My Current Keyboard is DUMB
2.I think i like the touch of the 高特(erm in direct translation, High Special) Keystrokes
3.I also like to emulate 8086 or z80s with my pi and keyboard and a hdmi screen but i realized a single esp32 could have done all things in a single PCB

## What it can do?
1.Bluetooth/USB keyboard support
2.Configurable Macro Support
3.Key Layout Remap Support
4.Emulate Z80 CP/M :D
5.may be also as a mini Piano?(Erm yah cuz why not?)

## Component List
| Name | SpecName | Usage | Quantities |
|---|---|---|---|
| KeyStrokes | For My Self,高特青軸 (im not sure what its called in english)| For the Switches on Keyboard!| 77 |
| KeyCaps | Cherry Key Caps | Key Caps that you press on | Depends |
| ESP32 MCU board | ESP32 S3 N16R8 | A controller board that handles the TFT screen display and Bluetooth Communication | 1 |
| TFT Screen | TFT 4inch Screen Module with 14 Pins | A medium size TFT that display the Emulated Content and also Let me reconfigure the Keyboard with GUI | 1 |
| KeyStroke Hot Swappable Holders | Kailh KeyStroke Holders | 77 |
| Speaker | 2W3718 Speaker Module | 1 |
| LED for Fn and Caps Signal | Any THT Led | 2 |
| LiBattery 3.7V | Any Capacity u want | 1 |
| LiBattery 3.7v-5v Protector Board and Charger Board | same as the name | 1 |
Also prepare some 2.54 Dupont Socket and PinHeaders incase if u may disassemble it or replace some modules.

## 3D printing List and Keycap List
|   | R1 | R2 | R3 | R4 |
|---|---|---|---|---|
|U1|Fn Alt Ctrl ArrowL ArrowR ArrowD ZXCVBNM,./ ArrowU|ASDFGHJKL;'|QWERTYUIOP[]|`1234567890-= Esc F1-12 Delete|
|U1.25|Win Alt Ctrl||||
|U1.5|||Tab \||
|U1.75||Caps Lock|||
|U2||||BackSpace|
|U2.25|Shift|Enter|||
|U5.25|Space||||
|   | R1 | R2 | R3 | R4 | SUM |
|---|---|---|---|---|---|
|U1|17|11|12|27|67|
|U1.25|3||||3|
|U1.5|||2||2|
|U1.75||1|||1|
|U2||||1|1|
|U2.25|1|1|||2|
|U5.25|1||||1|
|..|..|..|..|..|77|
