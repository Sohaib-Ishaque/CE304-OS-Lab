/*
 * In The Name of God
 * =======================================
 * [] File Name : main.c
 *
 * [] Creation Date : 20-11-2018
 *
 * [] Created By : Parham Alvani <parham.alvani@gmail.com>
 * =======================================
*/
/*
* Copyright (c)  2018 Parham Alvani.
*/
#include <stdio.h>

#include "slice.h"

int main(int argc, const char *argv[]) {
  struct slice_t *s = slice_new(10);
  slice_push(s, 11);
  printf("%d\n", slice_pop(s));
}
