#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
ll gcd(int x, int y) { return (x % y)? gcd(y, x % y): y; }    //最大公約数
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }     //最小公倍数
using Graph = vector<vector<ll>>;
ll inf=300000000000000000;
const double PI = 3.14159265358979323846;
int main(){
  int n,a,b;
  cin >> n >> a >> b;
  int x[n];
  int y[n];
  int z[n];
  rep(i,n)cin >> x[i] >> y[i] >> z[i];
  int dp[n+1][401][401];
  rep(i,n+1)rep(j,401)rep(o,401)dp[i][j][o]=1000000000;
  dp[0][0][0]=0;
  rep(i,n){
    rep(j,401)rep(o,401)dp[i+1][j][o]=dp[i][j][o];
    rep(j,401){
      rep(o,401){
        if(j-x[i]<0||o-y[i]<0)continue;
        dp[i+1][j][o]=min(dp[i+1][j][o],dp[i][j-x[i]][o-y[i]]+z[i]);
      }
    }
  }
  int ans=1000000000;
  rep(i,400){
    rep(j,400){
      int u=ans;
      if((i+1)/(gcd(i+1,j+1))==a&&(j+1)/(gcd(i+1,j+1))==b)ans=min(ans,dp[n][i+1][j+1]);
      //if(u!=ans)cout << i << " " << j << " " << ans << endl;
    }
  }
  if(ans==1000000000){
    cout << -1 << endl;
  }
  else cout << ans << endl;
}
