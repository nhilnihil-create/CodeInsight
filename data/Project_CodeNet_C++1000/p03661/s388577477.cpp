#include <iostream>
using namespace std;

const int N = 2e5 + 5;
typedef long long ll;

ll n, a[N], sum[N], ans = 1LL << 62;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	for (int i = 1; i <= n - 1; ++i) {
		ans = min(ans, abs(sum[n] - sum[i] - sum[i]));
	}
	cout << ans << endl;
	return 0;
}