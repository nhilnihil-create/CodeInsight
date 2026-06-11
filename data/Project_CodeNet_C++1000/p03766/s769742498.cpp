#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

const int N=1000005;
const int MOD=1000000007;

int n,f[N],s[N];

int main()
{
	scanf("%d",&n);
	f[1]=f[2]=f[0]=s[0]=1;s[1]=2;s[2]=3;
	for (int i=3;i<=n;i++)
	{
		f[i]=f[i-1]+s[i-3];
		f[i]-=f[i]>=MOD?MOD:0;
		s[i]=s[i-1]+f[i];
		s[i]-=s[i]>=MOD?MOD:0;
	}
	int ans=f[n];
	ans+=(LL)f[n-1]*(n-1)%MOD;
	ans-=ans>=MOD?MOD:0;
	for (int i=0;i<=n-2;i++) ans+=(LL)f[i]*((LL)(n-1)*(n-1)%MOD+i+1)%MOD,ans-=ans>=MOD?MOD:0;
	printf("%d",ans);
	return 0;
}