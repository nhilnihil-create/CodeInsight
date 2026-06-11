#include <bits/stdc++.h>
using ll = long long;
#define TEN(x) ((ll)1e##x)
const ll mod = TEN(9) + 7;
int main() {
	ll n; scanf("%lld", &n);
	ll sum = 1, num = 0;
	while (n--) {
		ll a; scanf("%lld", &a);
		num++;
		if (a / 2 + a % 2 < num) {
			sum = sum * num % mod;
			num--;
		}
	}
	while (num--) sum = sum * (num + 1) % mod;
	printf("%lld\n", sum);
}