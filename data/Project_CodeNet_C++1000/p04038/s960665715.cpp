//Achen
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<cstdio>
#include<queue>
#include<cmath>
#include<set>
#include<map>
#define For(i,a,b) for(int i=(a);i<=(b);i++)
#define Rep(i,a,b) for(int i=(a);i>=(b);i--)
const int N=2007,mod=1e9+7;
typedef long long LL; 
typedef double db;
using namespace std;
int n,k;
LL dp[N][N],fac[N*N],inv[N*N];

template<typename T> void read(T &x) {
    char ch=getchar(); x=0; T f=1;
    while(ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
    if(ch=='-') f=-1,ch=getchar();
    for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0'; x*=f;
}

LL C(int n,int m) {
	if(n<m) return 0;
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}

//#define DEBUG
int main() {
#ifdef DEBUG
	freopen("1.in","r",stdin);
	//freopen(".out","w",stdout);
#endif
	read(n); read(k);
	fac[0]=inv[0]=inv[1]=1;
	For(i,1,n*k) fac[i]=fac[i-1]*i%mod;
	For(i,2,n*k) inv[i]=(mod-mod/i*inv[mod%i]%mod)%mod;
	For(i,2,n*k) inv[i]=inv[i-1]*inv[i]%mod; 
	if(k==1) {
		puts("1");
		return 0;
	}
	dp[n][n]=1;
	Rep(i,n,0) {
		Rep(j,n,i) {
			if(i) 
				(dp[i-1][j]+=dp[i][j])%=mod;
			if(j>i) 
				(dp[i][j-1]+=dp[i][j]*(k>2?C(i+j*(k-1)-1,k-2):1)%mod)%=mod;
		}
	}
	LL ans=dp[0][0]*fac[n]%mod;
	printf("%lld\n",ans);
    return 0;
}