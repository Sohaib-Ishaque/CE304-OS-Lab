/*
 * In The Name Of God
 * ========================================
 * [] File Name : code-code.c
 *
 * [] Creation Date : 23-11-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Parham Alvani.
*/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int say_hello(const char *name)
{
	int i;

	for (i = 0; i < 4; i++)
		printf("hello %s\n", name);
}

int main(int argc, char *argv[])
{
	pid_t pid;

	pid = fork();

	if (pid < 0) {
		perror("fork()");
	} else if (pid == 0) {
		say_hello("child");
		exit(0);
	} else {
		sleep(0.5);
		say_hello("parent");
	}
}
