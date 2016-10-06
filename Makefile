#Copyright © 2016 Brian Pomerantz. All Rights Reserved.

CC = gcc
CFLAGS = -Wall
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)
TARGET = run

USER_DEFINES=

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^ -lncurses $(USER_DEFINES)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o $(TARGET)
