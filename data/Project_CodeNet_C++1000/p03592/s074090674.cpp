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
  ll n,m,k; cin>>n>>m>>k;
  ll s = n*m;
  vector<bool> d(n*m+1, false);
  for (int i=0; i<=n; i++) {
    for (int j=0; j<=m; j++) {
      ll t = s - i*(m-j) - (n-i)*j;
      d[t] = true;
    }
  }
  if (d[k]) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
