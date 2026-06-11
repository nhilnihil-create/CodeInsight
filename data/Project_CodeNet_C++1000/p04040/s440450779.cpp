#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7, MX=200010;

int h, w, a, b;
ll F[MX]={1}, I[MX];

ll pw(ll a, int e){
	if(e==0) return 1;
	ll t = pw(a,e/2); t=t*t%MOD;
	return e%2 ? t*a%MOD : t;
}
ll C(int n, int r){
	return F[n]*I[r]%MOD*I[n-r]%MOD;
}
int main(){
	cin>>h>>w>>a>>b;
	for(int i=1; i<=200005; i++) F[i]=1LL*F[i-1]*i%MOD;
	for(int i=0; i<=200005; i++) I[i]=pw(F[i], MOD-2);

	ll ans=0;

	for(int i=b+1; i<=w; i++){
		ll now=C(i-1 + h-a-1, i-1);
		now = now * C(w-i + a-1, w-i) % MOD;
		ans = (ans+now)%MOD;
	}
	cout<<ans<<'\n';
	
	return 0;
}