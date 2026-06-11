#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); ++i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define fi first
#define se second
#define INF 1000000009
#define LLINF 1000000000000000009LL
using ll = long long;

vector<int> to[100009];
vector<int> a;
bool ok = true;

ll dfs(int v, int p=-1) {
  if (p != -1 && to[v].size() == 1) return a[v];
  ll sum = 0, mx = 0;
  for (auto u : to[v]) {
    if (u == p) continue;
    ll tmp = dfs(u, v);
    sum += tmp;
    chmax(mx, tmp);
  }
  if (sum > a[v] * 2 || a[v] > sum || mx > a[v]) ok = false;
  return a[v] * 2 - sum;
}

int main() {
  int n;
  cin >> n;
  a.resize(n);
  rep(i,n) cin >> a[i];
  rep(i, n-1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  bool ans = false;
  if (n == 2) {
    if (a[0] == a[1]) ans = true;
  }
  else {
    int s;
    rep(i,n) {
      if (to[i].size() > 1) s = i;
    }
    ans = (dfs(s) == 0 && ok);
  }
  if (ans) puts("YES");
  else puts("NO");
  return(0);
}