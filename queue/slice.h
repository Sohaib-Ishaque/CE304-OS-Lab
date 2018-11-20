/*
 * In The Name of God
 * =======================================
 * [] File Name : slice.h
 *
 * [] Creation Date : 20-11-2018
 *
 * [] Created By : Parham Alvani <parham.alvani@gmail.com>
 * =======================================
*/
/*
* Copyright (c)  2018 Parham Alvani.
*/
#ifndef SLICE_H
#define SLICE_H

struct slice_t {
    int size;
    int start;
    int end;
    int *values;
};

struct slice_t *slice_new(int size);

void slice_push(struct slice_t *, int);
int slice_pop(struct slice_t *);

#endif
