#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
constexpr ll INF = 1LL << 60;

int main() {
	ll x, y;
	cin >> x >> y;

	ll ans = INF;
	if (x <= y) ans = min(ans, y - x);
	if (x * y <= 0) ans = min(ans, abs(abs(y) - abs(x)) + 1);
	if (y < x) ans = min(ans, abs(abs(y) - abs(x)) + 2);
	cout << ans;
	return 0;
}
