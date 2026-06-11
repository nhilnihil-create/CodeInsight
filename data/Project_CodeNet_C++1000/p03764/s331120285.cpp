#include <stdio.h>
#include <stdlib.h>

#define MAX_M (100000)
#define MAX_N (100000)
#define NUM_MOD (1000000007)

int main(int argc, char *argv[]) {
  // read inputs
  long n, m, xs[MAX_M], ys[MAX_N];
  scanf("%ld %ld", &n, &m);
  for (long j = 0; j < n; j++) {
    scanf("%ld", &xs[j]);
  }
  for (long i = 0; i < m; i++) {
    scanf("%ld", &ys[i]);
  }

  // solve
  long int_row = 0, int_col = 0;
  for (long i = 0; i < m - 1; i++) {
    int_row += (i + 1) * (m - (i + 1)) * (ys[i + 1] - ys[i]);
    int_row %= NUM_MOD;
  }
  for (long j = 0; j < n - 1; j++) {
    int_col += (j + 1) * (n - (j + 1)) * (xs[j + 1] - xs[j]);
    int_col %= NUM_MOD;
  }
  printf("%ld\n", (int_row * int_col) % NUM_MOD);

  return 0;
}
