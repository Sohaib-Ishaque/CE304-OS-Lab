all: ps ipc

CFLAGS=-Wall -O0 -g -std=gnu11

ps: ps/vfork.out ps/fork.out

ipc: ipc/pipe.out ipc/fifo-server.out ipc/fifo-client.out ipc/shmget.out ipc/shm-client.out ipc/shm-server.out

thread: thread/hello.out thread/arg.out thread/retval.out

# each .c file compiles to a stanalone .out executable
%.out: %.c
	$(CC) -o $@ $< $(CFLAGS)

.PHONY: clean
clean:
	rm **/*.out
