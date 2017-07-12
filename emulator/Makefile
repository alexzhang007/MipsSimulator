CC     := g++
CFLAGS := -g 
TARGET := mips_sim
SRCS   := $(wildcard *.cpp)
OBJS   := $(patsubst %cpp,%o, $(SRCS))
all    :$(TARGET)
%.o : %.cpp
	$(CC) $(CFLAGS) -c $<
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
run:
	./$(TARGET)
clean:
	rm -f $(TARGET) *.o
