CC=arm-none-eabi-gcc
CFLAGS=-mcpu=cortex-m4 -mthumb -nostdlib
CPPFLAGS=-DSTM32G431xx \
	 -I dependencies/CMSIS/Device/ST/STM32G4/Include \
	 -I dependencies/CMSIS/CMSIS/Core/Include

LINKER_FILE=linker_script.ld
LDFLAGS=-T $(LINKER_FILE)


all: blink.elf

blink.elf: main.o startup.o system_stm32g4xx.o
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $^ -o blink.elf

main.o: src/main.c
	$(CC) $(CFLAGS) $(CPPFLAGS) src/main.c -c

startup.o: src/startup.c
	$(CC) $(CFLAGS) $(CPPFLAGS) src/startup.c -c

system_stm32g4xx.o: dependencies/CMSIS/Device/ST/STM32G4/Source/Templates/system_stm32g4xx.c
	$(CC) $(CFLAGS) $(CPPFLAGS) dependencies/CMSIS/Device/ST/STM32G4/Source/Templates/system_stm32g4xx.c -c


.PHONY: clean
clean:
	rm -f *.o *.elf *.s


blinky_example: blinky_example.elf

blinky_example.elf: blinky_example_main.o startup.o system_stm32g4xx.o
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $^ -o blinky_example.elf

blinky_example_main.o: samples/blinky_example/blinky_example_main.c
	$(CC) $(CFLAGS) $(CPPFLAGS) samples/blinky_example/blinky_example_main.c -c


assembly: main.s

main.s: src/main.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -S $^ -o main.s


PROGRAMMER=openocd
PROGRAMMER_FLAGS=-f ~/openocd/tcl/interface/stlink.cfg -f ~/openocd/tcl/target/stm32g4x.cfg

flash: blink.elf
	$(PROGRAMMER) $(PROGRAMMER_FLAGS) -c "program blink.elf verify reset exit"


blinky_example_flash: blinky_example
	$(PROGRAMMER) $(PROGRAMMER_FLAGS) -c "program blinky_example.elf verify reset exit"

