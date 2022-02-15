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
include sources.mk 

ifeq ($(PLATFORM),HOST)
# Platform Overrides
PLATFORM = HOST

# Compiler Flags and Defines
CC = gcc
ASFLAGS = -S
CFLAGS = -Wall -Werror -g -std=c99
CPPFLAGs = -E
LDFLAGS = -Wl,-Map=main.map
PFLAGS = -MT -M -MM -MD -MP

# Header Files
HEADERS = platform.h misc.h msp432p401r.h msp_compatibilty.h system_msp432p401r.h

else
# Platform Overrides
PLATFORM = MSP432

# Architectures Specific Flags
LINKER_FILE = -T msp432p401r.lds
CPU = cortex-m4
ARCH = armv7e-m
SPECS = nosys.specs


# Compiler Flags and Defines
CC = arm-none-eabi-gcc
ASFLAGS = -S
CFLAGS = -Wall -Werror -g -std=c99 -mcpu=$(CPU)  \
          -march=$(ARCH) --specs=$(SPECS) -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 \
	  $(LINKER_FILE)
CPPFLAGs =  –E 
LDFLAGS = -Wl,-Map=main.map
DEPFLAGS = -MT -M -MM -MD -MP

endif



#

# To generate a preprocessed file for each source file
%.i: %.c
	$(CC) -D$(PLATFORM) $(SOURCES) $(CFLAGS) $(CPPFLAGS) -o $@ $< $(INCLUDES)


# To generate an assembly file for each source file
%.asm: %.c
	$(CC) -D$(PLATFORM) $(SOURCES) $(CFLAGS) $(ASFLAGS) -o $@ $< $(INCLUDES)


#To generate an assembly file for the final executable file
c1m2.asm: c1m2.out
	$(CC) -D$(PLATFORM) $(SOURCES) $(CFLAGS) $(ASFLAGS) -o $@ $< $(INCLUDES)


# To generate an object file for each source file
%.o: %.c
	$(CC) -D$(PLATFORM) $(SOURCES) $(CFLAGS) -c -o $@ $< $(INCLUDES)


dep: $(SOURCES)
	$(CC) -D$(PLATFORM) $(SOURCES) $(CFLAGS) $(INCLUDES) $(DEPFLAGS)


#Compile all object files, but DO NOT link.
.PHONY: compile-all
compile-all: $(SOURCES)
	$(CC) -D$(PLATFORM) $(CFLAGS) -c $^ $(INCLUDES)


#Compile all object files and link into a final executable and generate map file
.PHONY: build
build: $(SOURCES)
	$(CC) -D$(PLATFORM) $(SOURCES) $(CFLAGS) $(INCLUDES) -c
	$(CC) -D$(PLATFORM) $(SOURCES) $(CFLAGS) $(INCLUDES) -o c1m2.out
	$(CC) -D$(PLATFORM) $(SOURCES) $(CFLAGS) $(INCLUDES) $(LDFLAGS)
	size c1m2.out


#Remove all output files
.PHONY: clean
clean:
	rm *.i *.asm *.o *.out *.d *.map




