#include <bits/stdc++.h>

using namespace std;

#define foru(i, l, r) for (register int i = l; i <= r; i++)
#define ford(i, r, l) for (register int i = r; i >= l; i--)

int read() {
  int res = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) res = res * 10 + c - '0', c = getchar();
  return res;
}

const int maxn = 1e5 + 5;
vector<int> G[maxn];
void link(int u, int v) {
  G[u].push_back(v);
  G[v].push_back(u);
}
int N, M, Q, mx[maxn], col[maxn];
int v[maxn], d[maxn], c[maxn];

void dfs(int x, int _mx, int _col) {
  if (!col[x]) col[x] = _col;
  if (_mx <= mx[x] || !_mx) return;
  mx[x] = _mx;
  for (auto to : G[x]) dfs(to, _mx - 1, _col);
}

int main() {
  //  freopen("b.in", "r", stdin);
  //  freopen("b.out", "w", stdout);
  N = read(), M = read();
  foru(i, 1, M) link(read(), read());
  Q = read();
  foru(i, 1, Q) v[i] = read(), d[i] = read(), c[i] = read();
  ford(i, Q, 1) dfs(v[i], d[i], c[i]);
  foru(i, 1, N) printf("%d\n", col[i]);
  return 0;
}
