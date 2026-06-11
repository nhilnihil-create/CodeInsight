#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<cassert>
#include<vector>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,a) for(int i=start[(a)];i;i=e[i].next)
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
#define fi first
#define se second
#define mkr(a,b) make_pair(a,b)
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int maxn=2e3+20;
const int mod=1e9+7;
inline void pls(int &a,int b){ a+=b;if(a>=mod)a-=mod;}

int jc[maxn*maxn],jcn[maxn*maxn],inv[maxn*maxn];

int n,k;

inline void init()
{
	n=read();k=read();
	if(k==1)puts("1"),exit(0);
	jc[0]=jcn[0]=inv[1]=jcn[1]=jc[1]=1;
	REP(i,2,n*k)inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod,jc[i]=(ll)i*jc[i-1]%mod,jcn[i]=(ll)inv[i]*jcn[i-1]%mod;
}

inline int C(int n,int m){ return (ll)jc[n]*jcn[m]%mod*jcn[n-m]%mod;} 

int dp[maxn][maxn];

inline void doing()
{
	dp[1][0]=1;
	REP(i,1,n)
	{
		REP(j,0,i)
		{
			if(i<n)pls(dp[i+1][j],dp[i][j]);
			if(j<i)pls(dp[i][j+1],(ll)dp[i][j]*C(n*k-i-(j)*(k-1)-1,k-2)%mod*(n-j)%mod);
		}
	}
	printf("%d\n",dp[n][n]);
}

int main()
{
	init();
	doing();
	return 0;
}

