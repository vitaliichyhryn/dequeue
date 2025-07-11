CC = gcc
CFLAGS = -std=c23
TARGET_DIR = target
TARGET = $(TARGET_DIR)/main
SOURCES = list.c main.c

all: $(TARGET)

$(TARGET_DIR):
	mkdir -p $(TARGET_DIR)

$(TARGET): $(SOURCES) | $(TARGET_DIR)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET)
	rm -rf $(TARGET_DIR)

.PHONY: clean
