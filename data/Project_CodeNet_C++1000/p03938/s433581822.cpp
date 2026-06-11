#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 20001, base = 20009;
inline int read() {
  char c = getchar();
  int x = 0, f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * f;
}
int N, a[MAXN], b[MAXN];
int main() {
  N = read();
  for (int i = 1; i <= N; i++) a[i] = base * i;
  for (int i = 1; i <= N; i++) b[i] = base * (N - i + 1);
  for (int i = 1; i <= N; i++) {
    int x = read();
    a[x] -= (N - i + 1);
  }
  for (int i = 1; i <= N; i++) printf("%d ", a[i]);
  puts("");
  for (int i = 1; i <= N; i++) printf("%d ", b[i]);
  return 0;
}
