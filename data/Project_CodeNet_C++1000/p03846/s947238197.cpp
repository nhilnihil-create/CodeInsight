#include <cstdio>
int main() {
  int N, a, A[100000]{};
  scanf("%d", &N);
  for (int i = 0; i != N; ++i) scanf("%d", &a), ++A[a];
  A[0] += N % 2;
  for (int i = (N + 1) % 2; i < N; i += 2)
    if (A[i] != 2) {
      printf("0\n");
      return 0;
    }
  N /= 2, a = 1;
  while (N--) a = a * 2 % 1000000007;
  printf("%d\n", a);
}
