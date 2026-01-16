CC := $(CROSS_COMPILE)gcc

CFLAGS := -Wall -Werror

all: writer

writer: writer.o
	$(CC) $(CFLAGS) writer.o -o writer

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f writer *.o