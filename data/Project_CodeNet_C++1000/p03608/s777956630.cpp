#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define VIEW(x) do {cerr << #x << ": "; for(auto i : x) cerr << i << " "; cerr << endl;} while(0)
#define ALL(x) (x).begin(),(x).end()
template<class T>bool umax(T &a, const T &b) {if(a<b){a=b;return 1;}return 0;}
template<class T>bool umin(T &a, const T &b) {if(b<a){a=b;return 1;}return 0;}

template<typename A,size_t N,typename T> void FILL(A (&array)[N],const T &val){fill((T*)array,(T*)(array+N),val);}
template<typename T> void FILL(vector<T> &v, const T &x) {fill(v.begin(), v.end(), x);}
template<typename T> void FILL(vector<vector<T>> &v, const T &x) {for(auto &i:v)fill(i.begin(), i.end(), x);}

#define INF (1LL <<50)
vector<vector<long long>> warshall_floyd(vector<vector<long long>> &adjmatrix) {
  int n = adjmatrix.size();
  vector<vector<long long>> dist(adjmatrix);
  for(int k = 0; k < n; ++k)
    for(int i = 0; i < n; ++i)
      for(int j = 0; j < n; ++j)
        if(dist[i][k]!=INF && dist[k][j]!=INF)
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
  return dist;
}

int main() {
  int n,m,R; cin >> n >> m >> R;
  vector<int> r(R);
  rep(i,R) {
    cin >> r[i];
    --r[i];
  }
  sort(ALL(r));

  vector<vector<ll>> adjmatrix(n, vector<ll>(n,INF));
  rep(i,m) {
    int a,b,c; cin >> a >> b >> c;
    --a,--b;
    adjmatrix[a][b] = c;
    adjmatrix[b][a] = c;
  }

  auto wf = warshall_floyd(adjmatrix);

  ll ans = INF;
  do {
    ll sum = 0;
    rep(i, R-1) {
      int from=r[i], to=r[i+1];
      sum += wf[from][to];
    }
    umin(ans,sum);
  }while(next_permutation(ALL(r)));
  cout << ans << endl;
}
