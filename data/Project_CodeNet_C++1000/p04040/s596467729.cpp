#include<iostream>
#include<cstdio>
#define p 1000000007
#define ll long long
using namespace std;
int h,w,a,b;
ll fac[202020],ans;
ll ksm(ll x,ll t)
{
	ll res=1;
	while(t)
	{
		if(t&1) res=res*x%p;
		x=x*x%p;
		t>>=1;
	}
	return res;
}
ll C(int x,int y){ return fac[x]*ksm(fac[y],p-2)%p*ksm(fac[x-y],p-2)%p;}
ll calc(int x,int y){ return C(x+y-2,x-1);}
int main()
{
	scanf("%d%d%d%d",&h,&w,&a,&b);
	fac[0]=fac[1]=1;
	for(int i=2;i<=h+w;i++)
		fac[i]=fac[i-1]*i%p;
	for(int i=1;i<=h-a;i++)
		(ans+=calc(i,b)*calc(h-i+1,w-b)%p)%=p;
	printf("%lld\n",ans);
	return 0;
}