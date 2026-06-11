#include<bits/stdc++.h>
using namespace std;
long long n,m,a,b,l,r,inv[200005],mod,num,power[35],u,cnt=1,fac[200005],fac_inv[200005],kmp,pp;
vector<long long> v;
int main()
{
	scanf("%lld%lld%lld%lld",&n,&m,&a,&b);
	l=n-a+b-1;
	r=n+b-2;
	mod=1000000007;
	pp=mod*10000;
	u=mod-2;
	while(1)
	{
		if(u<=1)
		{
			v.push_back(u);
			break;
		}else
		{
			v.push_back(u%2);
			u/=2;
		}
	}
	/*for(int i=0;i<v.size();i++)
	{
		printf("%lld ",v[i]);
	}
	printf("\n%lld\n",v.size());*/
	for(int i=0;i<=200000;i++)
	{
		inv[i]=1;
		power[0]=i;
		for(int j=1;j<=30;j++)
		{
			power[j]=power[j-1]*power[j-1];
			power[j]%=mod;
		}
		for(int j=0;j<v.size();j++)
		{
			if(v[j]==1)
			{
				inv[i]*=power[j];
				inv[i]%=mod;
			}
		}
	}
	for(int i=m;i<=n+m-2;i++)
	{
		cnt*=i;
		cnt%=mod;
	}
	for(int i=1;i<n;i++)
	{
		cnt*=inv[i];
		cnt%=mod;
	}
	fac[0]=1;
	for(int i=1;i<=200000;i++)
	{
		fac[i]=fac[i-1]*i;
		fac[i]%=mod;
	}
	fac_inv[0]=1;
	for(int i=1;i<=200000;i++)
	{
		fac_inv[i]=fac_inv[i-1]*inv[i];
		fac_inv[i]%=mod;
	}
	for(int i=n-a;i<=n-1;i++)
	{
		kmp=1;
		kmp*=fac_inv[i];
		kmp%=mod;
		kmp*=fac_inv[b-1];
		kmp%=mod;
		kmp*=fac[i+b-1];
		kmp%=mod;
		num=(n-i)-1;
		kmp*=fac[num+m-b-1];
		kmp%=mod;
		kmp*=fac_inv[num];
		kmp%=mod;
		kmp*=fac_inv[m-b-1];
		kmp%=mod;
		cnt-=kmp;
		cnt+=pp;
		cnt%=mod;
	}
	printf("%lld",cnt);
}