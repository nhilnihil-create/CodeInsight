#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
		
	int n, k, x, y; cin >> n >> k >> x >> y;

	int ans = 0;
	if (n <= k) {
		ans = x * n;
	}
	else if (k < n) {
		ans += x * k;
		ans += y * (n - k);
	}

	cout << ans << endl;
	return 0;
}