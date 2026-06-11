#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<stack>
#include<map>
#include<string>
#include<algorithm>
using namespace std;
#define inf 0x3f3f3f3f
#define ll long long

const ll mod = 1e9+7;
const int maxn = 200005;
ll f[maxn],inv[maxn];
int N;

ll Pow(ll a,ll b)
{
	ll ans=1;
	while(b){
		if(b&1) ans=(ans*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ans;
}

void init()
{
	f[0]=1;
	for(int i=1;i<=N;i++){
		f[i]=f[i-1]*i%mod;
	}
	inv[0]=1;
	inv[N]=Pow(f[N],mod-2);
	for(int i=N-1;i>0;i--){
		inv[i]=inv[i+1]*(i+1)%mod;
	}
}

ll C(int a,int b)
{
	if(a<0||b<0) return 1;
	return f[a]*inv[b]%mod*inv[a-b]%mod;
}

int main()
{
    ll n,m,a,b;
	scanf("%lld%lld%lld%lld",&n,&m,&a,&b);
	N=n+m-2;
	init();
	ll ans=C(n+m-2,n-1);
	for(ll i=1;i<=b;i++){
		ans-=C(n-a+i-2,n-a-1)*C(a-1+m-i,a-1);
		ans=(ans%mod+mod)%mod;
	}
	cout<<ans<<endl;
    return 0;
}