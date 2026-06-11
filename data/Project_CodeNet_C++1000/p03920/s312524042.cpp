#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  int i;
  int N;
  scanf("%d", &N);
  int num_max = 1;
  for (i = 1; i*(i+1) < 2*N; i++) {
    num_max += 1;
    //printf("%d ", num_max);
  }
  int ans[10000] = {};
  int index = 0;
  while (N > 0 && num_max >= 1) {
    if (N >= num_max) {
      ans[index] = num_max;
      N -= num_max;
      index += 1;
    }
    num_max -= 1;
  }
  for (i = 0; i < index; i++) {
    printf("%d\n", ans[i]);
  }
  return 0;
}