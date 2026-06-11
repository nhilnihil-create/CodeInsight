#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef long long ll;
typedef pair<int,int> P;

template <typename T>
void warshall_floyd(vector<vector<T>> &g) {
  for (int k = 0; k < g.size(); k++) {
    for (int i = 0; i < g.size(); i++) {
      for (int j = 0; j < g.size(); j++) {
        if (g[i][k] == INF || g[k][j] == INF) continue;
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
      }
    }
  }
}

int main(){
  int n,m,r;
  cin >> n >> m >> r;
  vector<vector<int>> to(n,vector<int>(n,INF));
  rep(i,n)to[i][i]=0;
  int d[r];
  rep(i,r){
    cin >> d[i];
    d[i]--;
  }
  sort(d,d+r);
  rep(i,m){
    int a,b,c;
    cin >> a >> b >> c;
    a--;b--;
    to[a][b] = c;
    to[b][a] = c;
  }
  warshall_floyd(to);
  ll ans = LINF;
  do {
    ll res = 0;
    rep(i,r-1){
      res += to[d[i]][d[i+1]];
    }
    chmin(ans,res);
  } while(next_permutation(d, d + r));
  cout << ans << endl;
  return 0;
}