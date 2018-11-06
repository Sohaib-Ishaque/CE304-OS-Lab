/*
 * In The Name of God
 * =======================================
 * [] File Name : shm-client.c
 *
 * [] Creation Date : 06-11-2018
 *
 * [] Created By : Parham Alvani <parham.alvani@gmail.com>
 * =======================================
 */
/*
 * Copyright (c)  2018 Parham Alvani.
 */

#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(int argc, const char *argv[]) {
  int shmid;
  key_t key = 0x01020304;
  void *addr;

  shmid = shmget(key, 4096, 0);
  if (shmid < 0) {
    fprintf(stderr, "failed to create shm segment\n");
    perror("shmget");
    return -1;
  }

  printf("found %d\n", shmid);

  addr = shmat(shmid, NULL, 0);
  if ((long long) addr == -1) {
    fprintf(stderr, "failed to attach\n");
    perror("shmat");
    return -1;
  }

  printf("got %p\n", addr);

  char *data = addr;

  printf("Data %s\n", data);

  return 0;
}
