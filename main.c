#include <stddef.h>
#include <stdio.h>
// #include "include/problem_a.h"
#include "include/problem_algo.h"

int main(void) {
  int result = prepare();

  if (result) {
    printf("error while preparing!");
    
  }
  run();
  clean();
  
  return 0;
}

