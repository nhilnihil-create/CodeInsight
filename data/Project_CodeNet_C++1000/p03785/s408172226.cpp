#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(int)(a); i++)
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
  ll n,c,k; cin>>n>>c>>k;
  vector<ll> t(n);
  rep(i, n) cin>>t[i];
  sort(t.begin(),t.end());

  ll ans = 1;
  ll g = t[0];
  ll f = 0;
  rep(i, n) {
    if (g+k < t[i] || f >= c) {
      g = t[i];
      f = 0;
      ans++;
    }
    f++;
  }
  cout << ans << endl;

  return 0;
}
