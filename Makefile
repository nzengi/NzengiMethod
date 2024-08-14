
### 4. **Optional: Makefile**

If you prefer to use `make`, here's a simple `Makefile`:

```Makefile
CC = g++
CFLAGS = -std=c++11 -Wall
SOURCES = src/main.cpp src/NzengiMethod.cpp
TARGET = NzengiMethod

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET)
