#include <cmath>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 200005
#define gc getchar
using namespace std;

inline int rd() {
  int x = 0;
  bool f = 0;
  char c = gc();
  while (!isdigit(c)) {
    if (c == '-') f = 1;
    c = gc();
  }
  while (isdigit(c)) {
    x = x * 10 + (c ^ 48);
    c = gc();
  }
  return f ? -x : x;
}

int n, tot, hd[N];

struct edge {int to, nxt;} e[N << 1];

inline void add(int u, int v) {
  e[++tot].to = u; e[tot].nxt = hd[v]; hd[v] = tot;
  e[++tot].to = v; e[tot].nxt = hd[u]; hd[u] = tot;
}

int dfs(int u, int fa) {
  int len = 0;
  for (int i = hd[u], v; i; i = e[i].nxt)
    if ((v = e[i].to) != fa) len = len ^ (dfs(v, u) + 1);
  return len;
}

int main() {
  n = rd();
  for (int i = 1; i < n; ++i) add(rd(), rd());
  puts(dfs(1, 0) ? "Alice" : "Bob");
  return 0;
}
