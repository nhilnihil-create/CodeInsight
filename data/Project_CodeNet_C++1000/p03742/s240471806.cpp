#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
  // read inputs
  long X, Y;
  scanf("%ld %ld", &X, &Y);

  // solve
  if (abs(X - Y) <= 1) {
    printf("Brown\n");
  } else {
    printf("Alice\n");
  }

  return 0;
}
