#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;
/*
题意:三种操作:添加0或者1到字符末尾,删除最右字符(若字符为空,则不变) 
给出string s 问有多少种长度为N的操作,能得到s n,|s|<=5000 .
*/
#define ll long long
const int mod=1e9+7;
int len,N,n;
ll dp[5021][5021];
string s;
ll powmod(ll x,ll n)
{
	ll s=1;
	while(n)
	{
		if(n&1)
			s=(s*x)%mod;
		x=(x*x)%mod;
		n>>=1;
	}
	return s;
}
int main(){
   dp[0][0]=1;
   for(int i=0;i<=5000;++i){
   	    for(int j=0;j<=5000;++j){
   	   	    if(dp[i][j]==0)continue;
   	   	    dp[i+1][j+1]=(dp[i+1][j+1]+2ll*dp[i][j]%mod)%mod;
   	   	    (dp[i+1][max(0,j-1)]+=dp[i][j]%mod)%=mod;
		}
   } 
   cin>>n>>s;
   ll l=s.size();
   ll ans=dp[n][l];
   ll t=powmod(2ll,l);
   ans=ans*powmod(t,mod-2)%mod;
   cout<<ans;
	return 0;
}
