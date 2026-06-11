#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int n, k;
	cin >> n >> k;
	long long ans = k;

	for (int i = 1; i < n; i++) {
		ans *= (k - 1);
	}

	cout << ans;
}