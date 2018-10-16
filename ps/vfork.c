/*
 * In The Name Of God
 * ========================================
 * [] File Name : code.c
 *
 * [] Creation Date : 19-11-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
 */
/*
 * Copyright (c) 2016 Parham Alvani.
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int x = 10;

int main(int argc, char *argv[])
{
	pid_t pid;
	int y = 5;

	pid = vfork();

	if (pid < 0) {
		perror("vfork():");
	} else if (pid == 0) {
		x++;
		y++;
		exit(0);
	} else {
		printf("parent\n");
		printf("x = %d - y = %d\n", x, y);
	}

	printf("x = %d - y = %d\n", x, y);
}
