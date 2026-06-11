#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for (int i = 0; i < (int)(a); i++)
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
typedef long long ll;
template<typename T>istream& operator>>(istream&i,vector<T>&v){rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(const vector<T>&v){stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename T>ostream& operator<<(ostream&o,const vector<T>&v){if(sz(v))o<<join(v);return o;}
template<typename T1,typename T2>istream& operator>>(istream&i,pair<T1,T2>&v){return i>>v.first>>v.second;}
template<typename T1,typename T2>ostream& operator<<(ostream&o,const pair<T1,T2>&v){return o<<v.first<<","<<v.second;}
template<typename T>bool mins(T& x,const T&y){if(x>y){x=y;return true;}else return false;}
template<typename T>bool maxs(T& x,const T&y){if(x<y){x=y;return true;}else return false;}
template<typename T>ll suma(const vector<T>&a){ll res(0);for(auto&&x:a)res+=x;return res;}

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
  ll n, m; cin>>n>>m;

  vector<int> aa(m);
  vector<int> bb(m);
  vector<int> cc(m);
  vector<vector<ll>> g(n, vector<ll>(n, inf));
  for (int i=0; i<m; i++) {
    ll a,b,c; cin>>a>>b>>c;
    a--; b--;
    mins(g[a][b], c);
    mins(g[b][a], c);
    aa[i] = a;
    bb[i] = b;
    cc[i] = c;
  }

  rep(k, n) rep(i, n) rep(j, n) mins(g[i][j], g[i][k]+g[k][j]);

  ll ans = m;
  rep(i, m) {
    if (g[aa[i]][bb[i]] == cc[i] && g[bb[i]][aa[i]] == cc[i]) ans--;
  }
  cout << ans << "\n";

  return 0;
}
