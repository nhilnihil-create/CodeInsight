#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdint>

int main() {
  int N;
  scanf("%d", &N);

  std::vector<int> A(N);
  for (int &a: A)
    scanf("%d", &a);

  for (int i=0; i<N; ++i)
    fprintf(stderr, "%d%c", A[i], i+1<N? ' ':'\n');

  intmax_t res=0, val=1;
  for (int i=0; i<N; ++i) {
    if (A[i] < val) continue;
    if (A[i] == val) {
      ++val;
      continue;
    }

    intmax_t num=(A[i]-1)/val;
    res += num;
    A[i] -= val*num;
    if (A[i] % val == 0) {
      A[i] = 1;
      if (val == 1) ++val;
    }
  }

  for (int i=0; i<N; ++i)
    fprintf(stderr, "%d%c", A[i], i+1<N? ' ':'\n');

  printf("%jd\n", res);
  return 0;
}
