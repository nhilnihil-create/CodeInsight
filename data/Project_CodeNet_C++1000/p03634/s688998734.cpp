#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int N = 100005;
const ll INF = 2e18;

vector<P> G[N];

int main() {
  int n;
  cin >> n;
  rep(i, n-1) {
    int a, b, c;
    cin >> a >> b >> c;
    --a; --b;
    G[a].push_back(make_pair(b, c));
    G[b].push_back(make_pair(a, c));
  }

  int q, k;
  cin >> q >> k;
  --k;
  vector<ll> d(n, INF);
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
  d[k] = 0;
  que.push(make_pair(0, k));
  while (que.size()) {
    int pos = que.top().second;
    que.pop();
    rep(i, G[pos].size()) {
      P p = G[pos][i];
      int to = p.first;
      if (d[pos] + p.second >= d[to]) continue;
      d[to] = d[pos] + p.second;
      que.push(make_pair(d[to], to)); 
    }
  }

  rep(i, q) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    ll ans = d[x] + d[y];
    cout << ans << endl;
  }

  return 0;
}