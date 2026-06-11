#include <stdio.h>
#include <stdlib.h>

#define MAX_N (100000)
#define MAX_H (1000000000)

using namespace std;

int main(int argc, char *argv[]) {
  // read inputs
  int N, A, B, hs[MAX_N];
  scanf("%d %d %d", &N, &A, &B);
  for (int i = 0; i < N; i++) {
    scanf("%d", &hs[i]);
  }

  // keep attacking the one with the most health
  int b = 0, e = MAX_H + 1;
  while (e - b > 1) {
    const long m = (b + e - 1) / 2, damage_all = m * B;
    long cnt = 0;
    for (int i = 0; i < N; i++) {
      const int h = hs[i];
      if (h > damage_all) {
        cnt += (h - damage_all + (A - B - 1)) / (A - B);
      }
    }
    if (cnt <= m) {
      e = m + 1;
    } else {
      b = m + 1;
    }
  }
  printf("%d\n", b);

  return 0;
}
