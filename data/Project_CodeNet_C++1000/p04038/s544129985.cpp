#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define int long long
#define Mod 1000000007ll
#define pow ksm
inline int ksm(int a,int x){
	LL ans=1,w=a;
	while(x){
		if(x&1)ans=ans*w%Mod;
		x>>=1;
		w=w*w%Mod;
	}
	return ans;
}
#define MN 4000005
#define mn 2005
int fac[MN],dfac[MN],n,k,f[mn][mn];
inline int C(int n,int m){
	return 1ll*fac[m]*dfac[n]%Mod*dfac[m-n]%Mod;
}
void init(int N){
	fac[0]=1;
	for(int i=1;i<=N;++i)
		fac[i]=fac[i-1]*i%Mod;
	dfac[N]=ksm(fac[N],Mod-2);
	for(int i=N-1;i>=0;--i){
		dfac[i]=(LL)dfac[i+1]*(LL)(i+1)%Mod;
	}
}
signed main(){
	scanf("%lld%lld",&n,&k);
	if(k==1){
		puts("1");
		return 0;
	}
	init(n*k);
	f[0][0]=1;
	for(int i=1;i<=n;++i)
		for(int j=0;j<=i;++j){
			f[i][j]=(f[i][j]+f[i-1][j])%Mod;
			if(j)f[i][j]=(f[i][j]+(f[i][j-1]*(n-j+1)%Mod*C(k-2,n-i+(k-1ll)*(n-j+1ll)-1ll)+Mod))%Mod;	
			//tm这式子谁顶得住啊
			//n-j+1: 有这么多种颜色可以这次放
			//k-2:放k-2个，为了不重，钦定第一个放剩下的第一个没填的格子
			//n-i+(k-1)*(n-j+1)-1：还剩下的格子数，-1的理由同上
		}
	printf("%lld",f[n][n]);
	return 0;
}
