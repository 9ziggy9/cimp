#include <stdio.h>
#include "./include/vector.h"

int main(void) {
  Vector_i32 vec = Vector_i32_init(4);
  Vector_i32_print(&vec);
  return 0;
}
