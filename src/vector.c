#include "../include/vector.h"

Vector_i32 Vector_i32_init(size_t capacity) {
  Vector_i32 v;
  v.len = 0;
  v.capacity = capacity;
  v.arr = (int32_t *) malloc(sizeof(int32_t) * capacity);
  return v;
}

void Vector_i32_destroy(Vector_i32 *v) {
  free(v->arr);
  v->arr = NULL;
  v->len = v->capacity = 0;
}

size_t Vector_i32_grow(Vector_i32 *v) {
  v->capacity *= 2;
  v->arr = realloc(v->arr, v->capacity * sizeof(int32_t));
  return v->capacity;
}

size_t Vector_i32_push(Vector_i32 *v, int32_t x) {
  if ((v->len + 1) / v->capacity >= 0.7) Vector_i32_grow(v);
  v->arr[v->len] = x;
  v->len++;
  return v->len;
}

void Vector_i32_print(Vector_i32 *v) {
  printf("[");
  for (size_t i = 0; i < v->len; i++) {
    printf("%d", v->arr[i]);
    printf("%c", i < v->len - 1 ? ',' : '\0');
  }
  printf("]\n");
}
