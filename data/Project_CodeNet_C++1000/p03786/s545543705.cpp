#include <bits/stdc++.h>

using namespace std;

int read() {
  int res = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) res = res * 10 + c - '0', c = getchar();
  return res;
}

const int maxn = 1e5 + 5;
int N, A[maxn], Ans = 0;
long long sum;

int main() {
  //  freopen("b.in", "r", stdin);
  //  freopen("b.out", "w", stdout);
  N = read(), sum = 0;
  for (int i = 1; i <= N; i++) A[i] = read();
  sort(A + 1, A + N + 1);
  for (int i = 1; i <= N; i++) {
    Ans++, sum += A[i];
    if(sum + sum < A[i + 1]) Ans = 0;
  }
  printf("%d\n", Ans);
  return 0;
}
