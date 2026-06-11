#include<iostream>
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
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(ll i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second
constexpr char ln = '\n';

const int mx=200010;
const ll mod=1e9+7;

int main(){
  int n,ma,mb;
  cin >> n >> ma >> mb;
  vector<int> a(n),b(n),c(n);
  rep(i,n){
    cin >> a[i] >> b[i] >> c[i];
  }
  vector<vector<vector<int>>> dp(50, vector<vector<int>>(450, vector<int>(450,inf)));
  dp[0][0][0]=0;
  rep(i,n){
    rep(j,410)rep(k,410){
      dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][k]);
      dp[i+1][j+a[i]][k+b[i]] = min(dp[i+1][j+a[i]][k+b[i]], dp[i][j][k] + c[i]); 
    }
  }

  int ans = inf;
  for(int i=1; i*ma<410 && i*mb<410; i++){
    ans = min(ans, dp[n][i*ma][i*mb]);
  }
  if(ans==inf) ans = -1;
  cout << ans << ln;
  return 0;
}