#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
  int i;
  int N, T;
  int A[100010], expensive[100010], diff[100010];
  scanf("%d %d", &N, &T);
  for (i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }
  expensive[N-1] = A[N-1];
  for (i = N-2; i >= 0; i--) {
    expensive[i] = max(expensive[i+1], A[i]);
  }
  int diffmax = 0;
  for (i = 0; i < N; i++) {
    diff[i] = expensive[i] - A[i];
  }
  sort(diff, diff + N);
  /*for (i = 0; i < N; i ++) {
    printf("%d ", diff[i]);
  }
  printf("\n");
  for (i = 0; i < N; i ++) {
    printf("%d ", expensive[i]);
    }*/
  diffmax = diff[N-1];
  int ans = 0;
  for (i = N-1; i >= 0; i--) {
    if (diff[i] == diffmax) {
      ans += 1;
    } else {
      break;
    }
  }
  printf("%d", ans); 
  return 0;
}
