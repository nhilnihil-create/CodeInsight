#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define all(A) A.begin(),A.end()
typedef long long ll;

int main(){
  
  int n,m;
  cin >> n >> m;
  vector<pair<int,bool>> dp(n,make_pair(1,0));
  dp[0].second = true;
  rep(i,m){
    int a,b;
    cin >> a >> b;
    a --;
    b --;
    dp[a].first --;
    dp[b].first ++;
    if(dp[a].second) dp[b].second = true;
    if(dp[a].first == 0) dp[a].second = false;
  }
  int ans = 0;
  rep(i,n) ans += dp[i].second;
  //debug
  //rep(i,n) cout << dp[i].first << "," << dp[i].second << endl;
  //debug
  cout << ans << endl;
}