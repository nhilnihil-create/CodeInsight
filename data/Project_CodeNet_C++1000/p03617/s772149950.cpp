#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;

int main() {
	ll price[4];
	for (int i = 0; i < 4; ++i) scanf("%lld", &price[i]);
	ll n; scanf("%lld", &n);
	price[0] /= 0.25, price[1] /= 0.5; // 2Lは誤差がでるため変換なし

	ll min_price = *min_element(price, price + 3);

	ll ans = 0;
	if (min_price > price[3] / 2) { //ここの除算の誤差は問題なし
		ans += (n / 2) * price[3];
		n -= (n / 2) * 2;

		ans += n * min_price;
	}
	else ans += min_price * n;

	printf("%lld\n", ans);
	return 0;
}