#include<bits/stdc++.h>
using namespace std;
long long f[2000000],n[2000000];
long long p=1000000007;
long long mi(long long x,long long y)
{
	long long ans=1;
	while(y)
	{
		if(y&1) ans=ans*x%p;
		x=x*x%p;
		y>>=1;
	}
	return ans;
}
long long mo(int x,int y)
{
	if(x==y||y==0)
	{
		return 1;
	}
	return ((f[x]*n[y])%p*n[x-y]%p);
}
long long need(int x1,int y1,int x2,int y2)
{
	return mo(x2-x1+y2-y1,x2-x1);
}
int main(){
	int nn,m,a,b,ans=0;
	f[1]=1;
	for(int i=2;i<=200000;i++)
	{
		f[i]=(f[i-1]*i)%p;
	}
	n[200000]=mi(f[200000],p-2);
	for(int i=199999;i>=1;i--)
	{
		n[i]=(n[i+1]*(i+1))%p;
	}
	cin>>nn>>m>>a>>b;
	for(int i=1;i<=nn-a;i++)
	{
		ans+=(need(1,1,i,b)*need(i,b+1,nn,m))%p;
		ans%=p;
	}
	cout<<ans;
	return 0;
}