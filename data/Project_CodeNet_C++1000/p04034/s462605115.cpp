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

int main()
{
  ll n,m; cin>>n>>m;
  vector<ll> x(m);
  vector<ll> y(m);
  rep(i, m) {
    cin>>x[i]>>y[i];
    x[i]--; y[i]--;
  }

  vector<bool> flg(n, false);
  flg[0] = true;
  vector<ll> a(n, 1);
  rep(i, m) {
    if (a[x[i]] <= 0) continue;

    if (flg[x[i]]) flg[y[i]] = true;
    a[x[i]]--;
    if (a[x[i]] <= 0) flg[x[i]] = false;
    a[y[i]]++;
  }

  ll ans = 0;
  rep(i, n) {
    if (flg[i]) ans++;
  }
  cout << ans << endl;

  return 0;
}
