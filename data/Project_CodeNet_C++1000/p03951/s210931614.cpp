#include <bits/stdc++.h>

using namespace std;

#define foru(i, l, r) for (register int i = l; i <= r; i++)
#define ford(i, r, l) for (register int i = r; i >= l; i--)

int N;
char S[100002];
char T[100002];

int main() {
  scanf("%d%s%s", &N, S + 1, T + 1);
  for (int len = N; len >= 1; len--) {
    bool flag = true;
    for (int i = N - len + 1, j = 1; i <= N && flag; i++, j++)
      if (S[i] != T[j]) flag = false;
    if (flag) return printf("%d\n", (N << 1) - len), 0;
  }
  printf("%d\n", N << 1);
  return 0;
}
