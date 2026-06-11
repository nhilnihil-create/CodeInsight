#include <stdio.h>
#include <stdlib.h>

#define MAX_N (100000)

int main(int argc, char *argv[]) {
  // read inputs
  int N, ps[MAX_N];
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &ps[i]);
    ps[i]--;  // NOTE : modified input
  }

  // solve
  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (i == ps[i]) {
      ans++;
      if (i + 1 < N && i + 1 == ps[i + 1]) {
        i++;  // move by 2
      }
    }
  }
  printf("%d\n", ans);

  return 0;
}
