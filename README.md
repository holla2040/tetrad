# hexad
A 4-axis ESP32 GRBL board 

Board
    ![hexad board](images/hexad-brd.png)
    [Schematic](board/hexad-sch.pdf)

Requires
    [ESP32SSDP](https://github.com/luc-github/ESP32SSDP)

Compiling
    Select Board "ESP32 Dev Module"
    Flash Size "4MB (32Mb)"
    Partition Scheme "Minimal SPIFFS (1.9MB APP with OTA/190kB SPIFFS)"

    set options, like N_AXIS in config.h

----
[![Watch the video](https://img.youtube.com/vi/7fjVDnm6PjQ/maxresdefault.jpg)](https://youtu.be/7fjVDnm6PjQ)




Based on Dring's ESP32 GRBL port
 * [Grbl_ESP32 Development Board Version 3.1](http://www.buildlog.net/blog/2018/11/grbl_esp32-development-board-version-3-1/) 
 * [Source](https://github.com/bdring/Grbl_Esp32)
 * [Schematic](http://www.buildlog.net/blog/wp-content/uploads/2018/10/schm_esp32_cnc_test_v3p1.pdf)
 * [Wiki](https://github.com/bdring/Grbl_Esp32/wiki)

