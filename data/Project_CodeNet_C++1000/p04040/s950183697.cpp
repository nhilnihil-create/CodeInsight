#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
const int maxn=2e5+100;
ll fac[maxn],f[maxn];
ll fpow(ll x, ll c) { ll res = 1; for (; c > 0; c >>= 1) { if (c & 1) res = res * x % mod; x = x * x % mod; }return res; }

ll comb(ll x, ll y) {
	return fac[x] * fpow(fac[y] * fac[x - y] % mod, mod - 2) % mod;
}

void init(int n) { fac[0] = fac[1] = 1; for(int i=2;i<=n;i++) fac[i] = i * fac[i - 1] % mod; }
int main(){
	init(200010);
	int n,m,a,b;
	cin>>n>>m>>a>>b;
	int x=n-a,y=b+1;
	ll ans=0;
  while(x>=1&&y<=m){
		ans=(ans+comb(x+y-1-1,x-1)*comb(n+m-x-y,n-x))%mod;
		x--,y++;
	}
	cout<<ans<<'\n';
}
		