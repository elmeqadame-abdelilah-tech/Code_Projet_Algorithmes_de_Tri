CC     = gcc
CFLAGS = -std=c11 -O2 -Wall -Wextra -Iinclude -MMD -MP

SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
DEP = $(OBJ:.o=.d)

ifeq ($(OS),Windows_NT)
  TARGET     = exucutable.exe
  RUN        = $(TARGET)
  RM_BUILD   = del /Q src\*.o src\*.d $(TARGET) 2>nul
  RM_RESULTS = del /Q results\*.dat data\les_entiers.bin results\*.png 2>nul
else
  TARGET     = exucutable
  RUN        = ./$(TARGET)
  RM_BUILD   = rm -f src/*.o src/*.d $(TARGET)
  RM_RESULTS = rm -f results/*.dat data/les_entiers.bin results/*.png
endif

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: all
	$(RUN)

clean:
	-$(RM_BUILD)

cleanall: clean
	-$(RM_RESULTS)

-include $(DEP)

.PHONY: all run clean cleanall