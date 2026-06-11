#include<cstdio>
using namespace std;
const int N=2005;
const int M=N*N;
const int mo=1e9+7;
int n,k,m;
long long p[M],q[M],f[N][N];
long long ksm(long long x,int y)
{
	long long t=1;
	for (;y;y>>=1)
	{
		if (y&1) t=t*x%mo;
		x=x*x%mo;
	}
	return t;
}
long long c(int x,int y){return p[x]*q[y]%mo*q[x-y]%mo;}
int main()
{
	scanf("%d%d",&n,&k),m=n*k;
	if (k==1){printf("1");return 0;}
	p[0]=q[0]=1;
	for (int i=1;i<=m;i++) p[i]=p[i-1]*i%mo;
	q[m]=ksm(p[m],mo-2);
	for (int i=m-1;i;i--) q[i]=q[i+1]*(i+1)%mo;
	f[0][0]=1;
	for (int i=1;i<=n;i++)
		for (int j=i;j>=0;j--)
		{
			f[i][j]=f[i][j+1];
			if (j) f[i][j]=(f[i][j]+f[i-1][j-1]*c(i*k-j-1,k-2))%mo;
		}
	printf("%lld",f[n][0]*p[n]%mo);
	return 0;
}
