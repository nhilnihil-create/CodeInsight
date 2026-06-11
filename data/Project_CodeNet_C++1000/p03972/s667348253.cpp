#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(a); i++)
typedef long long ll;

#ifdef _DEBUG
inline void dump() { cerr << endl; }
template<typename Head> void dump(Head&& head) { cerr << head; dump(); }
template<typename Head, typename... Tail> void dump(Head&& head, Tail&&... tail) { cerr << head << ", "; dump(forward<Tail>(tail)...); }
#define debug(...) do {cerr << __LINE__ << ":\t" << #__VA_ARGS__ << " = "; dump(__VA_ARGS__); } while (false)
#else
#define dump(...)
#define debug(...)
#endif

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
  ll w,h; cin>>w>>h;
  vector<ll> p(w);
  vector<ll> q(h);
  rep(i, w) cin>>p[i];
  rep(i, h) cin>>q[i];

  vector<pair<ll, ll>> g;
  rep(i, w) g.push_back(make_pair(p[i], 0));
  rep(i, h) g.push_back(make_pair(q[i], 1));
  sort(g.begin(),g.end());

  w++; h++;
  ll ans = 0;
  for (auto x:g) {
    ll v = x.first;
    ll u = x.second;
    if (u == 0) {
      ans += v*h;
      w--;
    } else {
      ans += v*w;
      h--;
    }
  }
  cout << ans << endl;

  return 0;
}
