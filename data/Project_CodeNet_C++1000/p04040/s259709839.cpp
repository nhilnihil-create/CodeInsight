#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define mod 1000000007
using namespace std;
long long n,m,a,b,ans;
long long fac[1000005];
long long qpow(long long base,long long t)
{
	long long ret=1;
	while(t)
	{
		if(t&1) ret=ret*base%mod;
		base=base*base%mod;
		t>>=1;
	}

	return ret;
}
long long C(long long N,long long M)
{
	if(!M) return 1;
	if(N<M) return 0;
  	return fac[N]*qpow(fac[M],mod-2)%mod*qpow(fac[N-M],mod-2)%mod;
}
long long solve(long long h,long long w)
{
	return C(h+w-2,h-1);
}
int main()
{
	int i,j;
	long long A,B,C,D,t1,t2,t;
	cin>>n>>m>>a>>b;
	fac[0]=1;
	for(i=1;i<=n+m;i++)
		fac[i]=fac[i-1]*i%mod;
	for(i=b+1;i<=m;i++)
	{
		t=solve(n-a,i)*solve(a,m-i+1)%mod;
		ans=(ans+t)%mod;
	}
	cout<<ans<<endl;
	return 0;
}