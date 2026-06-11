#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <iomanip>
#include <queue>
#include <algorithm>

using namespace std;
using ll = long long int;
const ll MOD = 1e9 + 7;

ll fast(ll n, ll k) {
	if (k == 0) {
		return 1;
	}
	if (k == 1) {
		return n;
	}
	if (k % 2 == 0) {
		ll tmp = fast(n, k / 2);
		return tmp * tmp % MOD;
	}
	else {
		ll tmp = fast(n, k / 2);
		tmp = tmp * tmp % MOD;
		return n * tmp % MOD;
	}
}

int main() {

	ll a, b, c;
	cin >> a >> b >> c;

	if (a % 2 == 0 || b % 2 == 0 || c % 2 == 0) {
		cout << 0 << endl;
	}
	else {
		cout << min(a * b, min(b * c, a * c)) << endl;
	}
}