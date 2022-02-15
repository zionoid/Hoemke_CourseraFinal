#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Landon Hoemke
#Embedded Software Engineering Course Final Project
#
#------------------------------------------------------------------------------
include sources.mk

# Platform overrides
COURSEFILE = course1
 
# Architectures specific flags
ifeq ($(PLATFORM), MSP432)
	LINKER_FILE = -T msp432p401r.lds 
	CPU = cortex-m4
	ARCH = armv7e-m
	SPECS = nosys.specs
else
	CPU = x86_64
	ARCH:=$(shell arch)
endif 

# Compiler flags and defines
ifeq ($(PLATFORM), MSP432)
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	LDFLAGS = -Wl,-Map=$(COURSEFILE).map $(LINKER_FILE) 
	# -Wl,option: If option contains commas, it is split into multiple options at the commas
	CFLAGS = -mcpu=$(CPU) -march=$(ARCH) --specs=$(SPECS) -mfloat-abi=hard -mfpu=fpv4-sp-d16 -mthumb -Wall -O0 -g -std=c99 
	CPPFLAGs = -M -MF test.d
	DEFINEFLAG = -DMSP432
else
	CC = gcc
	LDFLAGS = -Wl,-Map=$(COURSEFILE).map
	CFLAGS = -Wall -O0 -g -std=c99
	CPPFLAGs = -M -MF test2.d
	DEFINEFLAG = -DHOST
endif

ifeq ($(VERBOSE), TRUE)
	CFLAGS += -DVERBOSE
endif

ifeq ($(COURSE1), TRUE)
	CFLAGS += -DCOURSE1
endif

# Extra declared variables
OBJS:= $(SOURCES:.c=.o)
ASMS:= $(SOURCES:.c=.s)
PPS:= $(SOURCES:.c=.i)
MAPS:= $(SOURCES:.c=.map)
OUTS:= $(SOURCES:.c=.out)

%.i : %.c
	$(CC) $(CPPFLAGs) $(DEFINEFLAG) $<
	$(CC) $(DEFINEFLAG) -E -o $@ $<

%.asm : %.c
	$(CC) $(DEFINEFLAG) $(CFLAGS) -S $<
	objdump $(OBJS) -D

%.o : %.c
	$(CC) $(DEFINEFLAG) $(CFLAGS) -c $<

.PHONY: compile-all
compile-all: $(SOURCES)
#$(OBJS): $(SOURCES)
	$(CC) $(DEFINEFLAG) $(CFLAGS) -c $(SOURCES) -lm

.PHONY: build
build: $(OUTS)
#main.out
$(OUTS): $(SOURCES)
	$(CC) $(DEFINEFLAG) $(CFLAGS) $(LDFLAGS) -o course1.out $^ -lm
	size -Atd course1.out

.PHONY: clean
clean:
#rm -f $(OBJS) main.out $(ASMS) $(PPS) $(MAPS)
	rm -f *.i *.d *.map *.s *.out *.o

