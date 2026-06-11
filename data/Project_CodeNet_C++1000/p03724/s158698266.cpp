#include <bits/stdc++.h>

using namespace std;

#define foru(i, l, r) for (int i = l; i <= r; i++)
#define ford(i, r, l) for (int i = r; i >= l; i--)

int read() {
  int res = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) res = res * 10 + c - '0', c = getchar();
  return res;
}

const int maxn = 1e6 + 6;
int N, M, d[maxn], cnt;

int main() {
  //  freopen("b.in", "r", stdin);
  //  freopen("b.out", "w", stdout);
  N = read(), M = read();
  foru(i, 1, M) d[read()]++, d[read()]++;
  foru(i, 1, N) cnt += d[i] & 1;
  puts(cnt > 1 ? "NO" : "YES");
  return 0;
}
