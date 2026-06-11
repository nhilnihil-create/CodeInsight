#include <cstdio>
#include <algorithm>
typedef long long ll;
using namespace std;

int main() {
	ll a, b, c; scanf("%lld%lld%lld", &a, &b, &c);
	bool all_odd = true;
	if ((a & 1) == 0 || (b & 1) == 0 || (c & 1) == 0) {
		all_odd = false;
	}

	ll ans;
	if (all_odd) {
		ans = min({a * b, a * c, b * c});
	}
	else ans = 0;

	printf("%lld\n", ans);
	return 0;
}