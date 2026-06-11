#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define MAX_W (100000L)
#define MAX_H (100000L)
#define INF (1000000000L)

using namespace std;

int main(int argc, char *argv[]) {
  // read inputs
  long W, H, ps[MAX_W + 1], qs[MAX_H + 1];
  scanf("%ld %ld", &W, &H);
  for (int i = 0; i < W; i++) {
    scanf("%ld", &ps[i]);
  }
  for (int j = 0; j < H; j++) {
    scanf("%ld", &qs[j]);
  }

  // sort inputs
  ps[W] = INF;
  qs[H] = INF;
  sort(ps, ps + W + 1);
  sort(qs, qs + H + 1);

  // solve
  long ans = 0, m = 0, n = 0;
  while (m < W || n < H) {
    const long p = ps[m], q = qs[n];
    if (p < q) {
      ans += p * (H + 1 - n);
      m++;
    } else {
      ans += q * (W + 1 - m);
      n++;
    }
  }
  printf("%ld\n", ans);

  return 0;
}
