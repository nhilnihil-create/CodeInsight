#include<cstdio>
using ll = long long;
const static int MOD = 1000000007;

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	ll x = 0;
	for (int i = 0; i < n; ++i){
		ll tmp;
		scanf("%lld", &tmp);
		x += tmp*(i*2 - (n - 1));
	}
	x %= MOD;
	ll y = 0;
	for (int i = 0; i < m; ++i){
		ll tmp;
		scanf("%lld", &tmp);
		y += tmp*(i*2 - (m - 1));
	}
	y %= MOD;
	printf("%lld\n", x*y % MOD);
	return 0;
}