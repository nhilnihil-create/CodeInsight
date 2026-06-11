#include <iostream>

using namespace std;

int main(void) {
	long long a, b, x;
	cin >> a >> b >> x;

	long long ans, aa, ab;

	aa = a / x;
	ab = b / x;

	ans = ab - aa;
	if (a % x == 0) ans++;

	cout << ans;

	return 0;
}