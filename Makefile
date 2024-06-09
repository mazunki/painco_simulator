
CC = clang
CFLAGS = -O3 -Wall -Wextra -std=c99 -Iinclude

SRC = $(wildcard src/*.c)
INCLUDES = $(wildcard include/*.h)

TARGET = painco

$(TARGET): $(SRC) $(INCLUDES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

simulation: $(TARGET)
	./painco

#  vim: set ts=8

