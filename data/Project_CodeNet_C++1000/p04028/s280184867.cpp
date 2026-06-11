//Link : https://atcoder.jp/contests/arc059/tasks/arc059_d

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 5005
#define mod 1000000007
int dp[N][N];
int add(int x,int y) {
  int ret = x+y;
  if(ret>=mod) {
    return ret-mod;
  } else if(ret<0) {
    return ret + mod;
  }
  return ret;
}

int mul(int x,int y) {
  return (ll)x*y%mod;
}
int mypow(int x,int c) {
  int ret = 1;
  while(c--) {
    ret = mul(ret,x);
  }
  return ret;
}

void solve() {
  int n;string s;
  cin>>n>>s;
  dp[0][0] = 1;
  for(int numChar=1;numChar<=n;++numChar) {
    for(int len=0;len<numChar;++len) {
      dp[numChar][len+1] = add(dp[numChar][len+1],mul(2,dp[numChar-1][len]));
      dp[numChar][max(len-1,0)] = add(dp[numChar][max(len-1,0)], dp[numChar-1][len]);
    }
  }
  int u = mod/2+1;
  printf("%d\n", mul(dp[n][s.size()], mypow(u,s.size())) );
}

int main() {
  //freopen("input.txt","r",stdin);
  solve();
  return 0;
}
