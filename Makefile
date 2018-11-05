all: ps ipc

CFLAGS=-Wall -O0 -g -std=gnu11

ps: ps/vfork.out ps/fork.out

# each .c file compiles to a stanalone .out executable
%.out: %.c
	$(CC) -o $@ $< $(CFLAGS)

.PHONY: clean
clean:
	rm **/*.out
