#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int f[1000010],s[1000010],s1[1000010],n;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
	
}

int main()
{
	n=rd();
	if (n==1) { puts("1");return 0; }
	f[1]=s[1]=s1[1]=1;
	for (int i=2;i<=n;i++)
	{
		f[i]=((i>2?s1[i-3]:0)+1)%mod;
		s[i]=(s[i-1]+f[i])%mod;
		s1[i]=(s1[i-1]+s[i])%mod;
	}
	int ans=0;
	for (int i=1;i<n;i++) ans=(ll)(ans+(ll)f[i]*(n-1)%mod*n)%mod;
	ans=(ll)(ans+(ll)f[n]*(n-1))%mod;
	printf("%d\n",ans+1);
	return 0;
}