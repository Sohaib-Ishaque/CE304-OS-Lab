#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	int n;
	FILE *server;

	mkfifo("/tmp/parham_fifo_sv", S_IRUSR | S_IWUSR | S_IWGRP);
	server = fopen("/tmp/parham_fifo_sv", "r");

	for (;;) {
		printf("Waiting for client data\n");
		fscanf(server, "%d", &n);
		printf("You answer is: %d\n", (n * (n + 1)) / 2);
	}
}
