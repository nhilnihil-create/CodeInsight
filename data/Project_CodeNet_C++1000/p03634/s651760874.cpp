#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define VIEW(x) do {cerr << #x << ": "; for(auto i : x) cerr << i << " "; cerr << endl;} while(0)
//#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define ALL(x) (x).begin(),(x).end()
template<class T>bool umax(T &a, const T &b) {if(a<b){a=b;return 1;}return 0;}
template<class T>bool umin(T &a, const T &b) {if(b<a){a=b;return 1;}return 0;}
template<typename A,size_t N,typename T> void FILL(A (&array)[N],const T &val){fill((T*)array,(T*)(array+N),val);}
template<typename T> void FILL(vector<T> &v, const T &x) {fill(v.begin(), v.end(), x);}
template<typename T> void FILL(vector<vector<T>> &v, const T &x) {for(auto &i:v)fill(i.begin(), i.end(), x);}

struct edge{int to, dist;};
vector<edge> adj[100000];

signed main() {
  int n; cin >> n;
  rep(i,n-1) {
    int a,b,c; cin >> a >> b >> c; --a,--b;
    adj[a].push_back({b,c});
    adj[b].push_back({a,c});
  }
  int q,k; cin >> q >>  k; --k;

  vector<ll> d(n, -1);
  d[k] = 0;
  
  stack<int> st;
  st.push(k);
  while(st.size()) {
    int v = st.top(); st.pop();
    for(auto e : adj[v]) if(d[e.to]==-1) {
      d[e.to] = d[v] + e.dist;
      st.push(e.to);
    }
  }

  rep(i,q) {
    int x,y; cin >> x >> y; --x,--y;
    cout << d[x] + d[y] << endl;
  }
}
