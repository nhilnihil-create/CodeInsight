#include<bits/stdc++.h>
using namespace std;
long long mod=1000000000+7,n,m,h,w,jie[200003],ans;
long long mi(long long x,long long t)
{
	if(t==1)
		return x;
	long long sum=mi(x,t/2);
	sum=(sum*sum)%mod;
	if(t%2==1)
		sum=(sum*x)%mod;
	return sum;
}
long long c(long long n,long long m)
{
	return (mi((jie[n-m]*jie[m])%mod,mod-2)*jie[n])%mod;
}
int main()
{
	cin>>n>>m>>h>>w;
	jie[0]=1,jie[1]=1;
	for(long long i=2; i<=200000; i++)
		jie[i]=(jie[i-1]*i)%mod;
	for(long long i=1; h+i<=n&&w+i<=m; i++)
		ans=(ans+(c(n+w-h-1,w+i-1)*c(h+m-w-1,m-w-i)%mod))%mod;
	cout<<ans;
	return 0;
}