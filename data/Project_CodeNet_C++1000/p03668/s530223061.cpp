%:pragma GCC optimize("Ofast")
%:pragma GCC optimize("inline")
#include<bits/stdc++.h>
#define fo(i, n) for(int i = 1; i <= (n); i ++)
#define out(x) cout << #x << " = " << x << "\n"
#define type(x) __typeof((x).begin())
#define foreach(it, x) for(type(x) it = (x).begin(); it != (x).end(); ++ it)
using namespace std;
// by piano
template<typename tp> inline void read(tp &x) {
  x = 0; char c = getchar(); bool f = 0;
  for(; c < '0' || c > '9'; f |= (c == '-'), c = getchar());
  for(; c >= '0' && c <= '9'; x = (x << 3) + (x << 1) + c - '0', c = getchar());
  if(f) x = -x;
}
template<typename tp> inline void arr(tp *a, int n) {
  for(int i = 1; i <= n; i ++)
    cout << a[i] << " ";
  puts("");
}
const int N = 3e5 + 233;
int n;
vector<int> g[N];

inline int dfs(int u, int fat, int fff) {
  int t = 0;
  vector<int> vec;
  for(auto v: g[u]) if(v != fat) t ^= 1 + dfs(v, u, fff ^ 1);
  return t;
}

main(void) {
  read(n);
  for(int i = 1; i <= n - 1; i ++) {
    int x, y; read(x); read(y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  cout << (dfs(1, 0, 1) ? "Alice" : "Bob") << "\n";
}