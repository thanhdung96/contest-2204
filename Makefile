CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude
TARGET = bin/main
SRC = main.c src/file_helper.c src/problem_a.c

all: $(TARGET)

$(TARGET): $(SRC)
	mkdir -p bin
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

debug: CFLAGS += -g -O0 -DDEBUG
debug: clean $(TARGET)

clean:
	rm -rf bin

run: $(TARGET)
	./$(TARGET)

.PHONY: all debug clean run
