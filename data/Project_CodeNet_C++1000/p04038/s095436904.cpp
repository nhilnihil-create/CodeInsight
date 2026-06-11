#include<cstdio>
using namespace std;
typedef long long LL;
const int N=2003,p=1000000007;
int f[N][N],c[N*N],fc[N*N],i,j,k,n,m,K,X,z,an;

void plus(int &a,int b){ a+=b,a-=a<p?0:p; }

int power(int z,int k)
{
	int d=1;
	for (;k;z=(LL)z*z%p,k>>=1) if (k&1) d=(LL)d*z%p;
	return d;
}

int C(int n,int m)
{
	return (LL)c[n]*fc[m]%p*fc[n-m]%p;
}

int main()
{
	scanf("%d%d",&n,&K);
	if (K==1)
	{
		puts("1");
		return 0;
	}
	X=n*K;
	for (c[0]=i=1;i<=X;++i) c[i]=(LL)c[i-1]*i%p;
	for (fc[X]=power(c[X],p-2),i=X;i;--i) fc[i-1]=(LL)fc[i]*i%p;
	f[1][1]=1;
	for (i=1;i<n;++i)
		for (z=0,j=i;~j;--j)
			plus(z,f[i][j]),
			f[i+1][j+1]=(LL)z*C((i+1)*K-j-2,K-2)%p;
	for (i=1;i<=n;++i) plus(an,f[n][i]);
	printf("%d\n",(LL)an*c[n]%p);
	return 0;
}