#include<bits/stdc++.h>
#define LL long long
#define INF 0x3f3f3f3f
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
LL gcd(LL a,LL b)
{
	return b?gcd(b,a%b):a;
}
bool cmp(int x,int y)
{
	return x>y;
}
const int N=2e5+100;
const LL mod=1e9+7;
LL f[N],n,m,A,B;
LL powmod(LL x,LL n)
{
	LL s=1;
	while(n)
	{
		if(n&1)
			s=(s*x)%mod;
		x=(x*x)%mod;
		n>>=1;
	}
	return s;
}
LL C(LL n,LL m)
{
	LL a=f[n];
	LL b=(f[m]*f[n-m])%mod;
	return (a*powmod(b,mod-2))%mod;
}
int main()
{
	io;
	f[0]=1;
	for(LL i=1; i<N; i++)
		f[i]=(f[i-1]*i)%mod;
	while(cin>>n>>m>>A>>B)
	{
		LL res=0;
		for(LL i=B+1; i<=m; i++)
		{
			LL tmp=(C(i-1+n-A-1,n-A-1)*C(m-i+A-1,m-i))%mod;
			res=(res+tmp)%mod;
		}
		cout<<res<<endl;
	}
	return 0;
}