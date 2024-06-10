
CC = clang
CFLAGS = -O3 -Wall -Wextra -std=c99 -Iinclude

SRC = $(wildcard src/*.c)
INCLUDES = $(wildcard include/*.h)

TARGET = bin/painco

$(TARGET): $(SRC) $(INCLUDES)
	mkdir -p bin/
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

simulation: $(TARGET)
	$(TARGET)

#  vim: set ts=8

