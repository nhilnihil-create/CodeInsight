//AtCoder-2396
#include<cstdio>
#define ll long long
const int N=1e6+2,MOD=1e9+7;
int n,f[N],sum[N];
int main()
{
	f[1]=f[2]=f[0]=sum[0]=1;sum[1]=2;sum[2]=3;
	scanf("%d",&n);
	for(int i=3;i<=n;i++)
	{
		f[i]=f[i-1]+sum[i-3];
		f[i]-=f[i]>=MOD?MOD:0;
		sum[i]=sum[i-1]+f[i];
		sum[i]-=sum[i]>=MOD?MOD:0;
	}
	int ans=f[n];
	ans+=(ll)f[n-1]*(n-1)%MOD;
	ans-=ans>=MOD?MOD:0;
	for(int i=0;i<=n-2;i++)
	{
		ans+=(ll)f[i]*((ll)(n-1)*(n-1)%MOD+i+1)%MOD;
		ans-=ans>=MOD?MOD:0;
	}
	printf("%d",ans);
	return 0;
}