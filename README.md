# hexad
A 6-axis ESP32 GRBL board 

Based on Dring's ESP32 GRBL port
 * [Grbl_ESP32 Development Board Version 3.1](http://www.buildlog.net/blog/2018/11/grbl_esp32-development-board-version-3-1/) 
 * [Source](https://github.com/bdring/Grbl_Esp32)
 * [Schematic](http://www.buildlog.net/blog/wp-content/uploads/2018/10/schm_esp32_cnc_test_v3p1.pdf)
 * [Wiki](https://github.com/bdring/Grbl_Esp32/wiki)

Requires
    [ESP32SSDP](https://github.com/luc-github/ESP32SSDP)

Compiling
    Select Board "ESP32 Dev Module"
    Flash Size "4MB (32Mb)"
    Partition Scheme "Minimal SPIFFS (1.9MB APP with OTA/190kB SPIFFS)"

    set options, like N_AXIS in config.h
