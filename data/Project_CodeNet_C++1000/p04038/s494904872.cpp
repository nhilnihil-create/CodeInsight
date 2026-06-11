#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define inf 20021225
#define ll long long
#define mdn 1000000007
using namespace std;

int f[2100][2100];
int inv[2100*2100],fac[2100*2100];
int n,k;

int ksm(int bs,int mi)
{
	int ans=1;
	while(mi)
	{
		if(mi&1)	ans=(ll)ans*bs%mdn;
		bs=(ll)bs*bs%mdn; mi>>=1;
	}
	return ans;
}

int C(int x,int y)
{
	if(x<y)	return 0;
	return (ll)fac[x] * inv[y] %mdn * inv[x-y] %mdn;
}

int main()
{
	scanf("%d%d",&n,&k);
	if(k==1||n==1){printf("1\n");return 0;}
	inv[0]=fac[0]=1; int tot=n*k;
	for(int i=1;i<=tot;i++)	fac[i]=(ll)fac[i-1]*i%mdn;
	inv[tot] = ksm(fac[tot],mdn-2);
	for(int i=tot-1;i;i--)	inv[i]=(ll)inv[i+1]*(i+1)%mdn;
	f[0][0]=1;// printf("%d\n",inv[tot]);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			f[i][j] += f[i-1][j];
			if(j) f[i][j] += (ll)f[i][j-1] * C(tot-i-(k-1)*(j-1)-1,k-2) %mdn;
			f[i][j]%=mdn;
			//printf("%d %d %d\n",i,j,f[i][j]);
		}
	}
	printf("%d\n",(ll)f[n][n]*fac[n]%mdn);
	return 0;
}