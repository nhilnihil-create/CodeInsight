#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(long long)(n);i++)
#define all(a) a.begin(), a.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
const ll MOD=1e9+7;
const ll INF=1e18;
const int MAX=510000;
const double pi=acos(-1);
int dx[8] = {1,0,-1,0,1,1,-1,-1};
int dy[8] = {0,1,0,-1,-1,1,1,-1};
// int d[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

ll dp[55][55][3000];
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false); 
  
  int n,a;
  cin >> n >> a;
  vector<int> x(n);
  rep(i,n) cin >> x[i];
  
  memset(dp,0,sizeof(dp));
  dp[0][0][0]=1;
  rep(i,n){
    rep(j,n+1){
      rep(k,n*a+1){
        if(dp[i][j][k] == 0) continue;
        dp[i+1][j+1][k+x[i]] += dp[i][j][k];
        dp[i+1][j][k] += dp[i][j][k];
      }
    }
  }
  ll ans = 0;
  for(int j=1;j<=n;j++)ans+=dp[n][j][j*a];
  cout << ans << endl;

  return 0;
}
