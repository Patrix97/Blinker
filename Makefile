CC = gcc
CFLAGS = -c -Wall -pedantic

LDFLAGS =

SOURCES = ArrayList.c main.c arduino-serial-lib.c dmx.c
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = prog

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS)  $(OBJECTS) -o $(EXECUTABLE)

.c.o:
	$(CC) $(CFLAGS) -g $< -o $@

.PHONY: all clean cleanobj

clean: cleanobj
	rm $(EXECUTABLE)

cleanobj:
	rm *.o
