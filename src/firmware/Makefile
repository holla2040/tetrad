# add this to .arduino15/preferences.txt
build.path=/tmp/arduino_build

ino = $(wildcard *.ino)

hex:
	cp preferences.txt ~/.arduino15
	~/arduino/arduino --preserve-temp-files --verify $(ino)

usb:
	~/arduino/arduino --preserve-temp-files --upload --port /dev/ttyUSB0 $(ino) 

flash: ota

ota:
	python /home/holla/.arduino15/packages/esp32/hardware/esp32/1.0.4/tools/espota.py -i grblesp.local -p 3232 --auth= -f /tmp/arduino_build/$(ino).bin

clean:
	rm -rf /tmp/arduino*
