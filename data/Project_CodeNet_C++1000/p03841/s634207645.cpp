#include <bits/stdc++.h>
using namespace std;
const int N = 505, M = N * N;
int n, m, a[M], id[M], pos[N], pre[M], nxt[M];
inline void del(int x) {
  nxt[pre[x]] = nxt[x];
  pre[nxt[x]] = pre[x];
}
int main() {
  scanf("%d", &n);
  m = n * n;
  nxt[0] = 1, pre[m + 1] = m;
  for (int i = 1; i <= m; ++i) {
    pre[i] = i - 1;
    nxt[i] = i + 1;
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &pos[i]);
    for (int j = 1; j < i; ++j) {
      if (pos[i] == pos[j]) {
        puts("No");
        return 0;
      }
    }
    id[pos[i]] = i;
    a[pos[i]] = i;
    del(pos[i]);
  }
  sort(pos + 1, pos + n + 1);
  for (int i = 1; i <= n; ++i) {
    int rev = id[pos[i]];
    for (int j = 1, cur = 0; j < rev; ++j) {
      cur = nxt[cur];
      if (cur >= pos[i]) {
        puts("No");
        return 0;
      }
      a[cur] = rev;
      del(cur);
    } 
  }
  for (int i = n; i; --i) {
    int rev = id[pos[i]];
    for (int j = 1, cur = m + 1; j <= n - rev; ++j) {
      cur = pre[cur];
      if (cur <= pos[i]) {
        puts("No");
        return 0;
      }
      a[cur] = rev;
      del(cur);
    }
  }
  puts("Yes");
  for (int i = 1; i <= m; ++i) {
    printf("%d%c", a[i], i < m ? ' ' : '\n');
  }
  return 0;
}