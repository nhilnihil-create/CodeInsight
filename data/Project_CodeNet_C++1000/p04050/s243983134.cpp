#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX_N = 100005;

int N, M, A[MAX_N], B[MAX_N], odd;

int main() {
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= M; ++i) {
    scanf("%d", &A[i]);
    if (A[i] & 1) odd++;
  }

  if (M == 1) {
    if (N == 1) printf("1\n1\n1\n");
    else printf("%d\n2\n%d %d\n", N, N - 1, 1);
  } else if (odd <= 2) {
    for (int i = 1, num = 0; i <= M; ++i)
      if ((A[i] & 1) && num == 0) swap(A[1], A[i]), num++;
      else if ((A[i] & 1) && num == 1) swap(A[i], A[M]), num++;

    int tot = 0, sum = 0;
    for (int i = 1; i <= M; ++i) {
      sum += A[i];
      if (i != M && sum != 1) {
	B[++tot] = sum - 1;
      } else if (i == M) {
	B[++tot] = N;
      }
    }

    for (int i = 1; i <= M; ++i)
      printf("%d ", A[i]);
    puts("");

    printf("%d\n", tot);

    for (int i = 1; i <= tot; ++i)
      printf("%d ", B[i] - B[i - 1]);
    puts("");

  } else {
    puts("Impossible");
  }
  
  return 0;
}