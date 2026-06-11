#include<bits/stdc++.h>
#define MOD 1000000007
#define N 5005
using namespace std;

int n,dp[N][N];
char s[N];

int dfs(int rem,int stl) {

  if(rem<stl) return 0;
  if(rem==stl) return 1;
  if(~dp[rem][stl]) return dp[rem][stl];
  return dp[rem][stl]=((2*dfs(rem-1,stl+1))%MOD+dfs(rem-1,stl-(stl>0)))%MOD;

}

int main() {

  memset(dp,-1,sizeof(dp));
  scanf("%d %s",&n,s+1);
  int len=strlen(s+1);
  printf("%d",dfs(n,len));

}
