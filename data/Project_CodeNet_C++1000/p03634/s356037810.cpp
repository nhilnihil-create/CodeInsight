#include <bits/stdc++.h>
#define int long long
#pragma GCC optimize("O3")

#define fi first
#define se second
#define ep emplace
#define eb emplace_back
#define mp make_pair
#define pi pair<int,int>
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define vll vector<ll>
#define vpll vector<pair<ll,ll>>
#define endl '\n'

#define si(v) int((v).size())
#define all(v) (v).begin(), (v).end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i) 
#define rep2(i, n, m) for (ll i = n; i <= (ll)(m); ++i)
#define rep3(i, n, m) for (ll i = n; i >= (ll)(m); --i)

using ll = long long;
using ld = long double;
using namespace std;

constexpr ll MOD = 1000000007, MAX = 100001;

int n;
vector<vpi> edge(MAX);
int dst[MAX];

void dijkstra(int start)
{
  priority_queue<pi,vpi,greater<pi>> que;
  rep(i, MAX) dst[i] = 1e18;

  que.emplace(0, start);
  dst[start] = 0;

  while (!que.empty()) {
    auto p = que.top(); que.pop();
    int d = p.fi, from = p.se;

    if (dst[from] < d) continue;

    for (auto next : edge[from]) {
      int to = next.fi, dis = next.se;

      if (dst[to] > d + dis) {
        que.emplace(d + dis, to);
        dst[to] = d + dis;
      }
    }
  }
}

signed main()
{
  cout << fixed << setprecision(20);
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  rep(i, n-1) {
    int a, b, c; cin >> a >> b >> c;
    edge[a-1].eb(b-1, c);
    edge[b-1].eb(a-1, c);
  }

  int q, k; cin >> q >> k;
  dijkstra(k-1);

  rep(i, q) {
    int x, y; cin >> x >> y;
    cout << dst[x-1] + dst[y-1] << endl;
  }

  return (0);
}
