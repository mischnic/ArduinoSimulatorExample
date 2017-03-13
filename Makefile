CXX = clang++

CPPFLAGS = -I./ArduinoSimulator -I./ArduinoSimulator/core

sim:  Sketch.ino.o ArduinoSimulator/libArduinoSimulator.dylib
	$(CXX) -Wno-\#warnings -o sim Sketch.ino.o -L./ArduinoSimulator -lArduinoSimulator -DIS_SIM
	ln -sf ArduinoSimulator/libArduinoSimulator.dylib libArduinoSimulator.dylib

.PHONY: run
run: sim
	./sim

.PHONY: clean
clean:
	rm -f sim Sketch.ino.o

.PHONY: rebuild
rebuild: clean
	$(MAKE) -C ./ArduinoSimulator clean libArduinoSimulator.dylib
	$(MAKE) sim

ArduinoSimulator/libArduinoSimulator.dylib:
	$(MAKE) -C ./ArduinoSimulator libArduinoSimulator.dylib
