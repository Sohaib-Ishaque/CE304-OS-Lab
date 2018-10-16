#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int main (int argc, char *argv[])
{
	int filedes[2];
	int n;

	scanf("%d", &n);

	if (pipe(filedes) == -1)
		perror("pipe()");

	switch (fork()) {
		case -1:
			perror("fork()");
		case 0:
			if (close(filedes[0]) == -1)
				perror("close()");
			
			/* Child now writes to pipe */
			FILE *fw;

			fw = fdopen(filedes[1], "w");
			fprintf(fw, "%d\n", (n * (n + 1)) / 2);

			break;
		default:
			if (close(filedes[1]) == -1)
				perror("close()");

			/* Parent now reads from pipe */
			FILE *fr;
			int answer;
			
			fr = fdopen(filedes[0], "r");
			fscanf(fr, "%d", &answer);
			printf("%d\n", answer);

			break;
	}
}
