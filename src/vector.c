#include "../include/vector.h"

void Vector_i32_print(Vector_i32* v) {
  printf("[");
  for (size_t i = 0; i < v->len; i++) {
    printf("%d", v->arr[i]);
    printf("%c", i < v->len - 1 ? ',' : '\0');
  }
  printf("]\n");
}
