#include<iostream>
#define mod 1000000007
using namespace std;
long long x,y,tx,ans,fac[1000001],invfac[1000001];
void exgcd(long long a,long long b)
{
	if (b==0)
	{
		x=1;
		y=0;
		return;
	}
	exgcd(b,a%b); 
	tx=x;
	x=y;
	y=tx-a/b*y;
	return;
}
long long C(long long a,long long b)
{
	if (a>b)
		return 0;
	return fac[b]*invfac[a]%mod*invfac[b-a]%mod;
}
int main()
{
	int h,w,a,b;
	cin>>h>>w>>a>>b;
	h--;
	w--;
	a--;
	b--;
	fac[0]=1;
	for (int i=1;i<=1000000;++i)
		fac[i]=fac[i-1]*i%mod;
	exgcd(fac[1000000],mod);
	invfac[1000000]=x;
	for (int i=999999;i>=0;--i)
		invfac[i]=invfac[i+1]*(i+1)%mod;
	for (int i=a+1;i<=h;++i)
		ans=(ans+((C(i,w-b-1+i)-(i!=a+1)*C(i-1,w-b-2+i))%mod+mod)%mod*C(h-i,h-i+b+1)%mod)%mod;
	cout<<(ans+mod)%mod<<endl;
	return 0;
}