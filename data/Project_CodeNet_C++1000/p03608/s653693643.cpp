#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const int inf = 1001001001;
const ll INF = 1e18;

int main(){
  ll n,m,r;
  cin >> n >> m >> r;

  vector<ll> R(r);
  rep(i,r) {
    cin >> R[i];
    R[i]--;
  }

  vector<vector<ll>> g(n, vector<ll> (n,INF));

  // self roop
  rep(i,n){
    g[i][i] = 0;
   }
  
  rep(i,m){
      ll a, b, c;
      cin >> a >> b >> c;
      a--; b--;
      g[a][b] = c;
      g[b][a] = c;
  }

  // roop start from k?
  rep(k,n){
    rep(i,n){
      rep(j,n){
        g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
      }
    }
  }

  sort(R.begin(),R.end());

  ll ans = INF;

  do {
      ll sum = 0;
      rep(i,r-1){
        sum += g[R[i]][R[i+1]];
      }
      ans = min(ans,sum);
    }while(next_permutation(R.begin(), R.end()));
  cout << ans << endl;
}
