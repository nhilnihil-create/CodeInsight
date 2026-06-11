#include<bits/stdc++.h>
#define N (200009)
#define LL long long
#define MOD (1000000007)
using namespace std;

LL inv[N],fac[N],facinv[N];
LL h,w,a,b;

void Init()
{
	fac[0]=facinv[0]=inv[1]=1;
	for (int i=1; i<=200000; ++i)
	{
		if (i!=1) inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD;
		fac[i]=fac[i-1]*i%MOD; facinv[i]=facinv[i-1]*inv[i]%MOD;
	}
}

LL C(LL n,LL m)
{
	if (n<m) return 0;
	return fac[n]*facinv[m]%MOD*facinv[n-m]%MOD;
}

int main()
{
	Init();
	cin>>h>>w>>a>>b;
	LL ans=C(h+w-2,h-1);
	for (int i=1; i<=b; ++i)
		ans=(ans-C(h-a-1+i-1,i-1)*C(a-1+(w-i),a-1)%MOD)%MOD;
	cout<<(ans+MOD)%MOD;
}