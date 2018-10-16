#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	int n;
	FILE *server;

	server = fopen("/tmp/parham_fifo_sv", "w");

	do {
		scanf("%d", &n);
		printf("You entered: %d\n", n);
		fprintf(server, "%d\n", n);
		fflush(server);
	} while (n != 0);
}
