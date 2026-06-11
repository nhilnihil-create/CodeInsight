#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	const long long MOD = 1000000007;
	int n;
	cin >> n;
	long long ans = 1;
	for (int i = 1; i <= n; i++) {
		ans *= i;
		ans %= MOD;
	}

	cout << ans;

}