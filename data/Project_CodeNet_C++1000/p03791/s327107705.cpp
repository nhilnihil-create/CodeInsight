#include <cstdio>

typedef long long ll;

const int MAXN = 1E5 + 10;
const int MOD = 1E9 + 7;

int main(){
	int n;
	scanf("%d", &n);
	ll ans = 1;
	int res = 0;
	for (int x, i = 1; i <= n; ++i){
		scanf("%d", &x);
		++res;
		if (x < 2 * res - 1)
			ans = ans * res % MOD, --res;
	}
	for (; res; --res)
		ans = ans * res % MOD;
	printf("%lld\n", ans);
	return 0;
}
