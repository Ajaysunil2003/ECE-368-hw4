CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = a4
SRC = windows.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

test1: $(TARGET) #test case given in assignemnt pdf
	./$(TARGET) < test1.txt

test2: $(TARGET)
	./$(TARGET) < test2.txt

test3: $(TARGET)
	./$(TARGET) < test3.txt

test4: $(TARGET)
	./$(TARGET) < test4.txt

test5: $(TARGET)
	./$(TARGET) < test5.txt

test6: $(TARGET)
	./$(TARGET) < test6.txt


.PHONY: all clean run test