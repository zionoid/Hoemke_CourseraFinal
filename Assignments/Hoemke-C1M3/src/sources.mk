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


ifeq ($(PLATFORM),HOST)
# Add your Source files to this variable
SOURCES = main.c misc.c

# Add your include paths to this variable
INCLUDES = -I /home/landon/Hoemke-C1M3/include/common

else
# Add your Source files to this variable
SOURCES = main.c \
	  misc.c \
	  startup_msp432p401r_gcc.c \
	  system_msp432p401r.c \
	  interrupts_msp432p401r_gcc.c

# Add your include paths to this variable
INCLUDES = -I /home/landon/Hoemke-C1M3/include/common \
	   -I /home/landon/Hoemke-C1M3/include/CMSIS \
	   -I /home/landon/Hoemke-C1M3/include/msp432 \
	   -L /home/landon/Hoemke-C1M3

endif
