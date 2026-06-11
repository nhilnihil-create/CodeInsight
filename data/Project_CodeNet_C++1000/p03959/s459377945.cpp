#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define MAX_N (100000)
#define NUM_MOD (1000000007)

using namespace std;

int main(int argc, char *argv[]) {
  // read inputs
  int N, ts[MAX_N], as[MAX_N];
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &ts[i]);
  }
  for (int i = 0; i < N; i++) {
    scanf("%d", &as[i]);
  }

  // solve
  int hs[MAX_N], possible = 1;
  for (int i = 0; i < N; i++) {
    hs[i] = -1;
  }
  int prev;
  // check if it is possible
  prev = 0;
  for (int i = 0; i < N; i++) {
    const int h = ts[i];
    if (prev != h && as[i] < h) {
      possible = 0;
      break;
    }
    prev = h;
  }
  prev = 0;
  for (int i = N - 1; i >= 0; i--) {
    const int h = as[i];
    if (prev != h && ts[i] < h) {
      possible = 0;
      break;
    }
    prev = h;
  }
  // count
  prev = 0;
  for (int i = 0; i < N; i++) {
    const int h = ts[i];
    if (prev != h) {
      hs[i] = h;
    }
    prev = h;
  }
  prev = 0;
  for (int i = N - 1; i >= 0; i--) {
    const int h = as[i];
    if (prev != h) {
      hs[i] = h;
    }
    prev = h;
  }
  if (possible) {
    long ans = 1;
    for (int i = 0; i < N; i++) {
      if (hs[i] == -1) {
        ans = (ans * min(ts[i], as[i])) % NUM_MOD;
      }
    }
    printf("%ld\n", ans);
  } else {
    printf("0\n");
  }

  return 0;
}
