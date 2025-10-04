CC=arm-none-eabi-gcc
MACHINE=cortex-m4
CC_FLAGS=-c -mcpu=$(MACHINE) -mthumb  -mfloat-abi=soft -std=gnu11 -Wall -O0
LD_FLAGS =   -mcpu=$(MACHINE) -mthumb -mfloat-abi=soft --specs=nano.specs  -Wl,-Map=final.map -T stm32_ls.ld 
LD_FLAGS_SH =   -mcpu=$(MACHINE) -mthumb -mfloat-abi=soft --specs=rdimon.specs  -Wl,-Map=final.map -T stm32_ls.ld 

all: stm32_startup.o main.o led.o final.elf   syscalls.o

semihosting: stm32_startup.o main.o led.o final_sh.elf

stm32_startup.o: stm32_startup.c
	$(CC)  $(CC_FLAGS) $^ -o $@

syscalls.o: syscalls.c
	$(CC)  $(CC_FLAGS) $^ -o $@
	
main.o:main.c
	$(CC)  $(CC_FLAGS) $^ -o $@
	
led.o:led.c
	$(CC)  $(CC_FLAGS) $^ -o $@	

final.elf:stm32_startup.o main.o led.o syscalls.o
	$(CC)  $(LD_FLAGS) $^ -o $@	

final_sh.elf:stm32_startup.o main.o led.o 
	$(CC)  $(LD_FLAGS_SH) $^ -o $@	

clean:
	rm -rf *.o *.elf *.out

load:
	openocd -f board/stm32f4discovery.cfg