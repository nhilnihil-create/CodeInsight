#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

#define MAX_N (100000L)

using namespace std;

int main() {
  // read inputs
  long N, K, as[MAX_N], bs[MAX_N];
  scanf("%ld %ld", &N, &K);
  for (long i = 0; i < N; i++) {
    scanf("%ld %ld", &as[i], &bs[i]);
  }

  // enumerate the masks that need to be considered
  vector<long> masks;
  masks.push_back(K);
  for (long k = 0; k < 30; k++) {
    if (K & (1 << k)) {
      masks.push_back((K & ~(1 << k)) | ((1 << k) - 1));
    }
  }

  // solve
  long ans = 0;
  for (long mask : masks) {
    long score = 0;
    for (long i = 0; i < N; i++) {
      if ((as[i] & ~mask) == 0) {
        score += bs[i];
      }
    }
    ans = max(ans, score);
  }
  printf("%ld\n", ans);
}