#include <stdio.h>
#include "./include/vector.h"

int main(void) {
  Vector_i32 vec;
  Vector_i32_init(&vec, 4);
  for (int32_t i = 0; i < 10; i++) {
    Vector_i32_push(&vec, i);
  }
  /* Vector_i32_pop(&vec); */
  Vector_i32_print(&vec);
  Vector_i32_destroy(&vec);
  return 0;
}
