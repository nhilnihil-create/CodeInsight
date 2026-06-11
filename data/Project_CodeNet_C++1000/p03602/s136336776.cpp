#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <queue>

int main() {
  int N;
  scanf("%d", &N);

  std::vector<std::vector<int>> A(N, std::vector<int>(N));
  intmax_t res=0;
  for (int i=0; i<N; ++i)
    for (int j=0; j<N; ++j) {
      scanf("%d", &A[i][j]);
      res += A[i][j];
    }

  std::vector<std::vector<int>> B=A;
  for (int k=0; k<N; ++k)
    for (int i=0; i<N; ++i)
      for (int j=0; j<N; ++j)
	A[i][j] = std::min(A[i][j], A[i][k]+A[k][j]);

  if (A != B)
    return !printf("-1\n");

  for (int k=0; k<N; ++k)
    for (int i=0; i<N; ++i) {
      if (i == k) continue;
      for (int j=0; j<N; ++j) {
	if (j == k) continue;
	if (j == i) continue;
	if (A[i][j] == A[i][k] + A[k][j]) {
	  res -= A[i][j];
	  A[i][j] = 2e9;
	}
      }
    }

  printf("%jd\n", res>>1);
}
