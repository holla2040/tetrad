# add this to .arduino15/preferences.txt
build.path=/tmp/arduino_build

ino = $(wildcard *.ino)

bin:
#	/mnt/ramdisk/arduino/arduino-1.8.10/arduino-builder -dump-prefs -logger=machine -hardware /mnt/ramdisk/arduino/arduino-1.8.10/hardware -hardware /home/holla/.arduino15/packages -hardware /home/holla/Arduino/hardware -tools /mnt/ramdisk/arduino/arduino-1.8.10/tools-builder -tools /mnt/ramdisk/arduino/arduino-1.8.10/hardware/tools/avr -tools /home/holla/.arduino15/packages -built-in-libraries /mnt/ramdisk/arduino/arduino-1.8.10/libraries -libraries /home/holla/Arduino/libraries -fqbn=esp32:esp32:esp32:PSRAM=disabled,PartitionScheme=min_spiffs,CPUFreq=240,FlashMode=qio,FlashFreq=80,FlashSize=4M,UploadSpeed=921600,DebugLevel=none -ide-version=10810 -build-path /tmp/arduino_build -warnings=none -build-cache /tmp/arduino_cache_667762 -prefs=build.warn_data_percentage=75 -prefs=runtime.tools.esptool_py.path=/home/holla/.arduino15/packages/esp32/tools/esptool_py/2.6.1 -prefs=runtime.tools.esptool_py-2.6.1.path=/home/holla/.arduino15/packages/esp32/tools/esptool_py/2.6.1 -prefs=runtime.tools.xtensa-esp32-elf-gcc.path=/home/holla/.arduino15/packages/esp32/tools/xtensa-esp32-elf-gcc/1.22.0-80-g6c4433a-5.2.0 -prefs=runtime.tools.xtensa-esp32-elf-gcc-1.22.0-80-g6c4433a-5.2.0.path=/home/holla/.arduino15/packages/esp32/tools/xtensa-esp32-elf-gcc/1.22.0-80-g6c4433a-5.2.0 -prefs=runtime.tools.mkspiffs.path=/home/holla/.arduino15/packages/esp32/tools/mkspiffs/0.2.3 -prefs=runtime.tools.mkspiffs-0.2.3.path=/home/holla/.arduino15/packages/esp32/tools/mkspiffs/0.2.3 -verbose /home/holla/reference/e/espressif/esp32/boards/tetrad/src/firmware/firmware.ino
	/mnt/ramdisk/arduino/arduino-1.8.10/arduino-builder -compile -logger=machine -hardware /mnt/ramdisk/arduino/arduino-1.8.10/hardware -hardware /home/holla/.arduino15/packages -hardware /home/holla/Arduino/hardware -tools /mnt/ramdisk/arduino/arduino-1.8.10/tools-builder -tools /mnt/ramdisk/arduino/arduino-1.8.10/hardware/tools/avr -tools /home/holla/.arduino15/packages -built-in-libraries /mnt/ramdisk/arduino/arduino-1.8.10/libraries -libraries /home/holla/Arduino/libraries -fqbn=esp32:esp32:esp32:PSRAM=disabled,PartitionScheme=min_spiffs,CPUFreq=240,FlashMode=qio,FlashFreq=80,FlashSize=4M,UploadSpeed=921600,DebugLevel=none -ide-version=10810 -build-path /tmp/arduino_build -warnings=none -build-cache /tmp/arduino_cache_667762 -prefs=build.warn_data_percentage=75 -prefs=runtime.tools.esptool_py.path=/home/holla/.arduino15/packages/esp32/tools/esptool_py/2.6.1 -prefs=runtime.tools.esptool_py-2.6.1.path=/home/holla/.arduino15/packages/esp32/tools/esptool_py/2.6.1 -prefs=runtime.tools.xtensa-esp32-elf-gcc.path=/home/holla/.arduino15/packages/esp32/tools/xtensa-esp32-elf-gcc/1.22.0-80-g6c4433a-5.2.0 -prefs=runtime.tools.xtensa-esp32-elf-gcc-1.22.0-80-g6c4433a-5.2.0.path=/home/holla/.arduino15/packages/esp32/tools/xtensa-esp32-elf-gcc/1.22.0-80-g6c4433a-5.2.0 -prefs=runtime.tools.mkspiffs.path=/home/holla/.arduino15/packages/esp32/tools/mkspiffs/0.2.3 -prefs=runtime.tools.mkspiffs-0.2.3.path=/home/holla/.arduino15/packages/esp32/tools/mkspiffs/0.2.3 -verbose /home/holla/reference/e/espressif/esp32/boards/tetrad/src/firmware/firmware.ino


binold:
	cp preferences.txt ~/.arduino15
	~/arduino/arduino --preserve-temp-files --verify $(ino)

usb:
	python /home/holla/.arduino15/packages/esp32/tools/esptool_py/2.6.1/esptool.py --chip esp32 --port /dev/ttyUSB0 --baud 921600 --before default_reset --after hard_reset write_flash -z --flash_mode dio --flash_freq 80m --flash_size detect 0xe000 /home/holla/.arduino15/packages/esp32/hardware/esp32/1.0.4/tools/partitions/boot_app0.bin 0x1000 /home/holla/.arduino15/packages/esp32/hardware/esp32/1.0.4/tools/sdk/bin/bootloader_qio_80m.bin 0x10000 /tmp/arduino_build/firmware.ino.bin 0x8000 /tmp/arduino_build/firmware.ino.partitions.bin


usbold:
	~/arduino/arduino --preserve-temp-files --upload --port /dev/ttyUSB0 $(ino) 


flash: ota

ota:
	python /home/holla/.arduino15/packages/esp32/hardware/esp32/1.0.4/tools/espota.py -i grblesp.local -p 3232 --auth= -f /tmp/arduino_build/$(ino).bin

clean:
	rm -rf /tmp/arduino*
