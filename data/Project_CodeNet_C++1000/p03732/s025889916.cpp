#include<iostream>
#include <cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
  int N; ll W; cin >> N >> W; ll w[N], v[N], z[N];
  rep(i, N){
    cin >> w[i] >> v[i];
    z[i]=w[i]- w[0];
  }
  ll dp[110][110][310] = {}; 
  rep(i, N){
    rep(j, N){
      rep(k, 301){
        if(k>=z[j]) dp[i+1][j+1][k] = max(dp[i][j][k-z[j]]+v[j], dp[i+1][j][k]);
        else dp[i+1][j+1][k] = dp[i+1][j][k];
      }
    }
  }
  ll ans = 0;
  rep(i, N+1){
    rep(j, N){
      if(W-i*w[0]>=0) ans = max(ans, dp[i][N][min(W-i*w[0], (ll)300)]);
    }
  }
  cout << ans << endl;
}