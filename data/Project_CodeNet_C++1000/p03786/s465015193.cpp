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
const ll mod = 998244353;

int main()
{
  ll n; cin>>n;
  vector<ll> a(n);
  rep(i, n) cin>>a[i];
  sort(a.begin(),a.end());

  ll ans = n;
  ll sum = 0;
  rep(i, n-1) {
    sum += a[i];
    if (2*sum < a[i+1]) {
      ans = n-i-1;
    }
  }
  cout << ans << endl;

  return 0;
}
