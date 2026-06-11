/*
n=int(input())
mod=10**9+7
s=input()
l=len(s)

dp=[[0]*(n+3)  for i in range(n+1)]
#dp[n][x] := n回操作して文字列長x 

dp[0][0]=1
for i in range(1,n+1): #i回操作
    for j in range(i+1): #長さ j
        if j==0:
            dp[i][j]= dp[i-1][1]+dp[i-1][0]
        else:
            dp[i][j]= dp[i-1][j-1]*2+ dp[i-1][j+1]
#print(dp)
ans=dp[n][l]
waru = pow(2,l,mod)
ans= ans* pow(waru,-1,mod)
print(ans)
*/
#include <bits/stdc++.h>
using namespace std;
// mod. m での a の逆元 a^{-1} を計算する
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

int main() {
  //vector<vector<int>> dp(5020, vector<int>(5020));

  int n,l;
  long long mod = 1000000007;
  string s;
  cin>> n;
  cin>> s;
  l = s.length();
    long long dp[5020][5020];
    for (int i=0 ; i<5020 ; i++){
    for ( int j=0; j<5020 ; j++){
      dp[i][j]=0;}}
  // cout<< n<<s<<l<<endl;

  dp[0][0]=1;
  for (int i=1 ; i<n+1 ; i++){
    for ( int j=0; j<i+1 ; j++){
      if (j==0){
        dp[i][j]= (dp[i-1][1] + dp[i-1][0])%mod; }
      else{
        dp[i][j]= (2* dp[i-1][j-1] + dp[i-1][j+1])%mod;
      }
    }
  }
  long long ans = dp[n][l];
  //cout<< ans <<endl;
  
  for (int i=0 ; i<l ; i++){
    ans= ans* modinv(2,mod) % mod;
  }
  
  cout<< ans<<endl;
}