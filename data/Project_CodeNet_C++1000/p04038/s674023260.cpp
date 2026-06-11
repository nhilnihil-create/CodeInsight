#include<cstdio>
using namespace std;
typedef long long LL;
const int maxn=2005,TT=1000000007;
int n,K,fac[maxn*maxn],inv[maxn*maxn],F[maxn][maxn];
inline int read()
{
	int ret=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9'){ret=ret*10+ch-'0';ch=getchar();}
	return ret*f;
}
inline int QP(int a,int b)
{
	int ret=1,w=a;
	while(b)
	{
		if(b&1) ret=(LL)ret*w%TT;
		w=(LL)w*w%TT;b>>=1;
	}
	return ret;
}
inline int C(int n,int m){return (LL)fac[n]*inv[m]%TT*inv[n-m]%TT;}
int main()
{
	n=read();K=read();fac[0]=1;
	for(int i=1;i<=4000000;i++) fac[i]=(LL)fac[i-1]*i%TT;
	inv[4000000]=QP(fac[4000000],TT-2);
	for(int i=4000000-1;i>=0;i--) inv[i]=(LL)inv[i+1]*(i+1)%TT;
	if(K==1)
	{
		printf("%d\n",1);
		return 0;
	}
	F[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=i;j++)
			F[i][j]=(F[i-1][j]+(j?((LL)F[i][j-1]*(n-j+1)%TT*C(n*K-i-(j-1)*(K-1)-1,K-2)%TT):0))%TT;
	printf("%d\n",F[n][n]);
	return 0;
}