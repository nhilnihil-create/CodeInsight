#include<bits/stdc++.h>
using namespace std;
#define REP(i,st,ed) for(register int i=st,i##end=ed;i<=i##end;++i)
#define DREP(i,st,ed) for(register int i=st,i##end=ed;i>=i##end;--i)
typedef long long ll;
template<typename T>inline bool chkmin(T &x,T y){return (y<x)?(x=y,1):0;}
template<typename T>inline bool chkmax(T &x,T y){return (y>x)?(x=y,1):0;}
inline int read(){
	int x;
	char c;
	int f=1;
	while((c=getchar())!='-' && (c>'9' || c<'0'));
	if(c=='-') f=-1,c=getchar();
	x=c^'0';
	while((c=getchar())>='0' && c<='9') x=(x<<1)+(x<<3)+(c^'0');
	return x*f;
}
inline ll readll(){
	ll x;
	char c;
	int f=1;
	while((c=getchar())!='-' && (c>'9' || c<'0'));
	if(c=='-') f=-1,c=getchar();
	x=c^'0';
	while((c=getchar())>='0' && c<='9') x=(x<<1ll)+(x<<3ll)+(c^'0');
	return x*f;
}
const int maxn=2e3+10,mod=1e9+7;
inline int ksm(int x,int y){
	int res=1;
	while(y){
		if(y&1) res=(ll)res*x%mod;
		x=(ll)x*x%mod;
		y>>=1;
	}
	return res;
}
int dp[maxn][maxn],fac[maxn*maxn],ifac[maxn*maxn];
inline int C(int n,int m){
	return (ll)fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
inline void init(int n){
	fac[0]=1;
	REP(i,1,n) fac[i]=(ll)i*fac[i-1]%mod;
	ifac[n]=ksm(fac[n],mod-2);
	DREP(i,n,1) ifac[i-1]=(ll)i*ifac[i]%mod;
}
int main(){
	int n=read(),k=read();
	if(k==1){
		printf("1\n");
		return 0;
	}
	init(n*k);
	dp[0][0]=1;
	REP(i,1,n) REP(j,0,i){
		dp[i][j]=dp[i-1][j];
		if(j) dp[i][j]=(dp[i][j]+(ll)dp[i][j-1]*(n-j+1)%mod*C(n*k-i-(j-1)*(k-1)-1,k-2))%mod;
	}
	printf("%d\n",dp[n][n]);
	return 0;
}
