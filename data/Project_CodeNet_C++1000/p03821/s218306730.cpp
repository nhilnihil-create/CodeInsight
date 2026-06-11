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

ll gcd(ll a, ll b){return b==0 ? a : gcd(b, a%b);}
ll lcm(ll a, ll b){return a / gcd(a,b) * b;}

int main()
{
  ll n; cin>>n;
  vector<ll> a(n);
  vector<ll> b(n);
  rep(i, n) cin>>a[i]>>b[i];
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());

  ll ans = 0;
  rep(i, n) {
    ll m = (a[i]+ans)%b[i];
    if (m == 0) continue;
    ll t = b[i] - m;
    ans += t;
  }
  cout << ans << endl;

  return 0;
}
