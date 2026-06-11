#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<stack>
using namespace std;
const int mod = 1e9+7;
int dp[5010][5010],n,m;
char s[5010]; 
inline int pw(int x,int p){
	x%=mod;
	int res=1;
	while(p){
	  if(p&1)res=(long long)res*x%mod;
	  x=(long long)x*x%mod;
	  p>>=1;
	}
	return res;
}
int main(){
	int i,j,k;
	scanf("%d",&n);
	scanf("%s",s);
	m=strlen(s);
	dp[0][0]=1;
	for(i=1;i<=n;i++)
	  for(j=0;j<=i;j++){
	  	if(j)dp[i][j]=(dp[i][j]+dp[i-1][j-1]*2)%mod;
	  	if(j==0)dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
	  	dp[i][j]=(dp[i][j]+dp[i-1][j+1])%mod;
	  }
	int Ans=(long long)dp[n][m]*pw(pw(2,m),mod-2)%mod;
	printf("%d\n",Ans);
	return 0;
}