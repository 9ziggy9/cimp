#ifndef VECTOR_H_
#define VECTOR_H_

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct {
  size_t len;
  size_t capacity;
  uint32_t *arr;
} Vector_i32;

Vector_i32 Vector_i32_init(size_t capacity);
void Vector_i32_destroy(Vector_i32 *v);
void Vector_i32_print(Vector_i32 *v);

#endif // VECTOR_H_
