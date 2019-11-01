hex:
	arduino --preserve-temp-files --verify firmware.ino

usb:
	arduino --preserve-temp-files --upload --port /dev/ttyUSB0 firmware.ino

ota:
	python /home/holla/.arduino15/packages/esp32/hardware/esp32/1.0.4/tools/espota.py -i 192.168.0.196 -p 3232 --auth= -f /tmp/arduino_build_111289/firmware.ino.bin

clean:
	rm -rf /tmp/arduino*
