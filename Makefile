CXX = clang++

CPPFLAGS = -I./ArduinoSimulator -I./ArduinoSimulator/core

# .DEFAULT_GOAL = sim 
# sim:  Sketch.ino.o
# 	$(CXX) -o sim Sketch.ino.o -L./ArduinoSimulator -lArduinoSimulator

sim:  Sketch.ino.cpp ArduinoSimulator/libArduinoSimulator.dylib
	$(CXX) $(CPPFLAGS) -Wno-\#warnings -o sim Sketch.ino.cpp -L./ArduinoSimulator -lArduinoSimulator -DIS_SIM
	ln -sf ArduinoSimulator/libArduinoSimulator.dylib libArduinoSimulator.dylib

.PHONY: debug
debug:  Sketch.ino.cpp ArduinoSimulator/libArduinoSimulator.dylib
	$(CXX) $(CPPFLAGS) -o sim Sketch.ino.cpp -L./ArduinoSimulator -lArduinoSimulator -DIS_SIM


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

.PHONY: update
update:
	$(MAKE) -C ./ArduinoSimulator libArduinoSimulator.dylib

ArduinoSimulator/libArduinoSimulator.dylib:
	$(MAKE) -C ./ArduinoSimulator libArduinoSimulator.dylib