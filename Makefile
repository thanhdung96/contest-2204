CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude

TARGET = bin/main
SRC = main.c src/problem_a.c

all: $(TARGET)

$(TARGET): $(SRC)
	mkdir -p bin
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -rf bin

run: $(TARGET)
	./$(TARGET)
