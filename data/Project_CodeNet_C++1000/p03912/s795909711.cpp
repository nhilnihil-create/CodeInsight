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
  int n, m; cin>>n>>m;
  vector<ll> x(n);
  vector<ll> y(100001, 0);
  rep(i, n) {
    cin>>x[i];
    y[x[i]]++;
  }
  map<int, int> mp;
  map<int, int> mp2;
  rep(i, n) {
    mp[x[i]%m]++;
  }
  rep(i, 100001) {
    mp2[i%m] += y[i]/2;
  }

  int ans = mp[0]/2;
  for (int i=1; i<=m/2; i++) {
    int a = i;
    int b = m-i;
    if (a == b) {
      ans += mp[a]/2;
      continue;
    }
    if (mp[a] > mp[b]) swap(a, b);
    ans += mp[a];
    int tmp = (mp[b] - mp[a])/2;
    ans += min(mp2[b], tmp);
  }
  cout << ans << endl;

  return 0;
}
