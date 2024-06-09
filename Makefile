
CC = clang
CFLAGS = -Wall -Wextra -std=c99 -Iinclude

SRC = src/simulation.c
INCLUDES = $(wildcard include/*.h)

TARGET = painco

$(TARGET): $(SRC) $(INCLUDES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

simulation: $(TARGET)
	./painco

#  vim: set ts=8

