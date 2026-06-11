#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define ALL(v) v.begin(),v.end()
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;
using vs = vector<string>;
using vb = vector<bool>;
using vll = vector<long long>;
using vpii = vector<pair<int,int>>;
using vivi = vector<vector<int>>;
using vbvb = vector<vector<bool>>;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
const int mod = 1000000007;
const int inf = 1001001001;



int main(void) {
  int n;
  string a,b;
  cin >> n >> a >> b;
  vll dp(n+1);
  if(a[0]==b[0]){
    dp[1] = 3;
    rep2(i,1,n){
    if(a[i]==b[i]){
      if(a[i-1]==b[i-1]){
        dp[i+1] = dp[i]*2;
        dp[i+1]%=mod;
      }
      
      else{
        dp[i+1] = dp[i];
        dp[i+1]%=mod;
      }
    }
    else{
      if(a[i-1]==b[i-1]){
        dp[i+2] = dp[i]*2;
        dp[i+2]%=mod;
      }
      else {
        dp[i+2] = dp[i]*3;
        dp[i+2]%=mod;
      }
      i++;
    }
  }
  }
  else{
    dp[2] = 6;
    rep2(i,2,n){
    if(a[i]==b[i]){
      if(a[i-1]==b[i-1]){
        dp[i+1] = dp[i]*2;
        dp[i+1]%=mod;
      }
      
      else{
        dp[i+1] = dp[i];
        dp[i+1]%=mod;
      }
    }
    else{
      if(a[i-1]==b[i-1]){
        dp[i+2] = dp[i]*2;
        dp[i+2]%=mod;
      }
      else {
        dp[i+2] = dp[i]*3;
        dp[i+2]%=mod;
      }
      i++;
    }
  }
  }
  
  
  cout << dp[n] << endl;
}


