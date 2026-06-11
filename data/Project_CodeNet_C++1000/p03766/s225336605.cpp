#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int maxn=1e6+10;
ll dp[maxn],sum[maxn];
inline int Min(int x,int y){
	return x<y?x:y;
}
inline int read(){
	int x=0,flag=1;
	char ch=getchar();
	while(!isdigit(ch) && ch!='-')ch=getchar();
	if(ch=='-')flag=-1,ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return x*flag;
}
inline int Mod(int x){
	if(x>mod)x-=mod;
	return x;
}
int main(){
	int i,n;
	n=read();
	dp[0]=sum[0]=1;dp[1]=n;sum[1]=n+1;
	for(i=2;i<=n;i++){
		dp[i]=Mod(dp[i]+dp[i-1]);
		if(i>=3)dp[i]=(dp[i]+sum[i-3])%mod;
		dp[i]=(dp[i]+1ll*(n-1)*(n-1))%mod;
		dp[i]=(dp[i]+n-i+1)%mod;
		sum[i]=(sum[i-1]+dp[i])%mod;
	}
	printf("%lld\n",dp[n]);
	return 0;
}