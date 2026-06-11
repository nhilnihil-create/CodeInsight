#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
const double eps = 1e-10;
const int MOD = 1000000007;
const int INF = 1000000000;
const ll LINF = 1ll<<50;
template<typename T>
void printv(const vector<T>& s) {
  for(int i=0;i<(int)(s.size());++i) {
    cout << s[i];
    if(i == (int)(s.size())-1) cout << endl;
    else cout << " ";
  }
}
int dfs (int now, const vvi &t) {
  if((int)(t[now].size()) == 0) {
    return 0;
  } else {
    int res = 0;
    for(int i=0;i<(int)(t[now].size());++i) {
      res ^= 1 + dfs(t[now][i], t);
    }
    return res;
  }
}
int main() {
  cin.tie(0);
  cout << fixed << setprecision(10);
  int n; cin >> n;
  vvi g(n);
  for(int i=0;i<n-1;++i) {
    int x, y; cin >> x >> y;
    x--; y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  vvi t(n);
  queue<P> que;
  que.push({0, -1});
  while(!que.empty()) {
    int now = que.front().first, prev = que.front().second; que.pop();
    for(int i=0;i<(int)(g[now].size());++i) {
      int next = g[now][i];
      if(next != prev) {
        t[now].push_back(next);
        que.push({next, now});
      }
    }
  }
  int ans = dfs(0, t);
  cout << (ans==0 ? "Bob" : "Alice") << endl;
}
