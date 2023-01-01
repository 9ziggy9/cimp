#ifndef VECTOR_H_
#define VECTOR_H_

#include <stdio.h>
#include <stdint.h>

typedef struct {
  size_t len;
  size_t capacity;
  uint32_t* arr;
} Vector_i32;

#endif // VECTOR_H_
