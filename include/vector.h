#ifndef VECTOR_H_
#define VECTOR_H_

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

typedef struct {
  size_t len;
  size_t capacity;
  int32_t *arr;
} Vector_i32;

void Vector_i32_init(Vector_i32 *v, size_t capacity);
void Vector_i32_destroy(Vector_i32 *v);
void Vector_i32_print(Vector_i32 *v);
size_t Vector_i32_push(Vector_i32 *v, int32_t x);
size_t Vector_i32_grow(Vector_i32 *v);
size_t Vector_i32_pop(Vector_i32 *v);

#endif // VECTOR_H_
