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
  string s; cin>>s;

  ll ans = inf;
  rep(a, 26) {
    string t = s;
    ll step = 0;
    while (1) {
      ll n = t.size();
      string u = "";
      bool flg = true;
      rep(i, n-1) {
        if (t[i] != t[i+1]) flg = false;
        if (t[i] - 'a' == a) u.push_back(t[i]);
        else u.push_back(t[i+1]);
      }
      if (flg) break;
      t = u;
      step++;
    }
    ans = min(ans, step);
  }
  cout << ans << endl;

  return 0;
}
