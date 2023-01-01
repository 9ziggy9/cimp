#include "../include/vector.h"

Vector_i32 Vector_i32_init(size_t capacity) {
  Vector_i32 v;
  v.len = 0;
  v.capacity = capacity;
  v.arr = (uint32_t*) malloc(sizeof(uint32_t) * capacity);
  return v;
}

void Vector_i32_destroy(Vector_i32 *v) {
  free(v->arr);
  v->arr = NULL;
  v->len = v->capacity = 0;
}

void Vector_i32_print(Vector_i32 *v) {
  printf("[");
  for (size_t i = 0; i < v->len; i++) {
    printf("%d", v->arr[i]);
    printf("%c", i < v->len - 1 ? ',' : '\0');
  }
  printf("]\n");
}
