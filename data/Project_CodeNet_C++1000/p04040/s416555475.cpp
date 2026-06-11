#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7, N = 300005;

ll h, w, a, b, ans, fac[N] = {1}, fi[N] = {1};

ll comb (ll A, ll B) {
	return fac[A] * fi[B] % mod * fi[A-B] % mod;
}

ll calc (ll A, ll B, ll C, ll D) {
	return comb(D - B + A - C, D - B);
}

ll Pow (ll A, ll B) {
	if(!B) return 1;
	ll R = Pow(A, B/2);
	R = R * R % mod;
	if(B&1) R = R * A % mod;
	return R;
}

int main()
{
	scanf("%lld%lld%lld%lld",&h,&w,&a,&b);
	for(ll i=1;i<N;i++) {
		fac[i] = fac[i-1] * i % mod;
		fi[i] = Pow(fac[i], mod-2);
	}
	for(ll i=1;;i++) {
		ll X = a+i, Y = b+i;
		if(X > h || Y > w) break;
		ans = (ans + calc(h, 1, X, Y) * calc(X, Y, 1, w)) % mod;
	}
	printf("%lld\n",ans);
}
