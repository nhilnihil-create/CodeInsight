#include<bits/stdc++.h>
#define int long long
#define N 4000005
using namespace std;
const int mod=1e9+7;
int n,k,f[2005][2005],jc[N],invjc[N];
int power(int x,int y)
{
	int ans=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
	{
		if (y&1) ans=1LL*ans*x%mod;
	}
	return ans;
}
void init()
{
	jc[0]=1;
	for (int i=1;i<N;i++) jc[i]=1LL*jc[i-1]*i%mod;
	invjc[N-1]=power(jc[N-1],mod-2);
	for (int i=N-2;i>=0;i--) invjc[i]=1LL*invjc[i+1]*(i+1)%mod;
}
int C(int n,int m)
{
//	cout<<"!!!"<<n<<"!!!"<<m<<" "<<jc[n]<<" "<<invjc[m]<<" "<<invjc[n-m]<<endl;
	return 1LL*jc[n]*invjc[m]%mod*invjc[n-m]%mod;
}
signed main()
{
	init();
	scanf("%lld%lld",&n,&k);
	if (k==1)
	{
		printf("1\n");
		return 0;
	}
	f[0][0]=1;
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<=i;j++)
		{
			f[i][j]=f[i-1][j];
			if (!j) continue;
			(f[i][j]+=1LL*f[i][j-1]*(n-j+1)%mod*C(n*k-i-1-(j-1)*(k-1),k-2)%mod)%=mod;
		}
	}
	printf("%lld\n",f[n][n]);
	return 0;
}