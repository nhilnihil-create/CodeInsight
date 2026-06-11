#include <bits/stdc++.h>
using namespace std;
const long long N = 2000 + 20;
long long a[N], ans = 1ll * 1000 * 1000 * 1000 * 1000 * 1000, b[N];
int main() {
	long long n, x;
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> a[i], b[i] = ans;
	}
	for (int i = 0; i <= n; i++) {
		long long ps = 0;
		for (int j = 0; j < n; j++) {
			long long y = ((j - i) + n) % n;
			b[j] = min(b[j], a[y]);
			ps += b[j];
		}
		ans = min(ans, x * i + ps);
	}
	cout << ans;
	return 0;
}