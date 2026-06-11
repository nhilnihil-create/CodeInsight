#include <iostream>
typedef long long ll;
using namespace std;

const ll MOD = 1000000007;

int main() {
	int n; scanf("%lld", &n);

	int ans = 1;
	for (ll times = 1; times <= n; ++times) {
		ans = (ans * times) % MOD;
	}

	printf("%lld", ans);
	return 0;
}