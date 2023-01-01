#include "../include/vector.h"

// PAY FUCKING ATTENTION DAVID
// Previously this code was defined as a Vector_i32 pointer;
// Vector_i32 v was defined, its struct slots set, then
// reference to v return.
// RETURNING REFERENCE TO STACK-ALLOCATED MEMORY WILL LEAD
// TO UNDEFINED BEHAVIOR!
void Vector_i32_init(Vector_i32 *v, size_t capacity) {
  v->len = 0;
  v->capacity = capacity;
  v->arr = (int32_t *) malloc(sizeof(int32_t) * capacity);
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

size_t Vector_i32_pop(Vector_i32 *v) {
  assert(0 && "IMPLEMENT ME: Vector_i32_pop()\n");
  // TODO:
  // PROBLEM HERE, do all entries need to be pointers?
  /* &v->arr[v->len - 1] = NULL; */
  // Note that we are not doing any garbage colletion!
  // We need to implement some type of logic to deallocate
  // dead memory. Perhaps when the length of the array is 
  // sufficiently small, we ought to realloc via some type
  // of "shrinking" mechanism.

  // SOME NOTES ON FREEING MEMORY AND REALLOC
  /* Firstly, realloc might decide to */

  /* 1. Allocate a new memory block, copy data,
     and free the original one, or */

  /* 2. Simply expand/contract the original block "in place"
     without allocating the new one. */

  /* Which approach it will choose depends on the implementation
     and various other external factors. It might follow the first
     approach. Or it might follow the second approach. You can easily
     figure out which approach it followed by comparing the values of
     pointers i and m after realloc. */

  /* Secondly, if realloc decided to follow the first approach
     (i.e. allocate a new memory block), then the old block is indeed
     freed by realloc. In that case trying to access the original
     memory location leads to undefined behavior. */

  /* If realloc decided to follow the second approach
     (i.e. expand or shrink the original memory block "in place"),
     then m and i will keep pointing to the same location. In that
     case there's no surprise in seeing the same data through m. */

  /* P.S. This means that the behavior of your code is either trivial
     or undefined. It can't really be used to analyze whether the
     behavior is "proper". */
  return 0;
}

void Vector_i32_print(Vector_i32 *v) {
  printf("[");
  for (size_t i = 0; i < v->len; i++) {
    printf("%d", v->arr[i]);
    printf("%c", i < v->len - 1 ? ',' : '\0');
  }
  printf("]\n");
}
