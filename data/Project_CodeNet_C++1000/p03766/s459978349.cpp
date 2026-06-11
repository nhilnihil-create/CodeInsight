#include<bits/stdc++.h>
using namespace std;
#define re register
#define in inline
#define ll long long
#define get getchar()
#define mian main
const int _=1e6+10;
const int mod=1e9+7;
ll f[_];
int main()
{
	ll n;
	scanf("%lld",&n);
	f[n]=n;
	f[n-1]=(n*n)%mod;
	ll ans=0;
	for (re int i=n-2; i>=1; i--)
	{
		ans=(ans+f[i+3])%mod;
		f[i]=((((f[i+1]+((n-1)*(n-1))%mod)%mod)+ans)%mod+i+1)%mod;
	}
	cout<<f[1]<<endl;
	return 0;
}
