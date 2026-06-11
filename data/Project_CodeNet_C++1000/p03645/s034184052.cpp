#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(a); i++)
typedef long long ll;
template<typename T>
struct edge {
  int src, to;
  T cost;
  edge(int to, T cost) : src(-1), to(to), cost(cost) {}
  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}
  edge &operator=(const int &x) {
    to = x;
    return *this;
  }
  operator int() const { return to; }
};
template<typename T>
using Edges = vector<edge<T>>;
template<typename T>
using WeightedGraph = vector<Edges<T>>;
using UnWeightedGraph = vector<vector<int>>;
template<typename T>
using Matrix = vector<vector<T>>;

/////////////////////////////////////////////////////////////////////

const ll inf = 1LL<<60;
const ll mod = 1000000007;

int main()
{
  ll n,m; cin>>n>>m;
  vector<bool> st(n, false);
  vector<bool> ed(n, false);
  rep(i, m) {
    ll a,b; cin>>a>>b; a--; b--;
    if (a == 0) st[b] = true;
    if (b == n-1) ed[a] = true;
  }

  bool flg = false;
  rep(i, n) {
    if (st[i] && ed[i]) flg = true;
  }

  if (flg) cout << "POSSIBLE" << endl;
  else cout << "IMPOSSIBLE" << endl;

  return 0;
}
