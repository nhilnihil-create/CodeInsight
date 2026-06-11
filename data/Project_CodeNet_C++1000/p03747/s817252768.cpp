#include <iostream>
#include <algorithm>

using namespace std;

long long x[100001], endx[100001];
long long w[100001];

int main() {
#ifdef ONLINE_JUDGE
	ios_base::sync_with_stdio(false);
#endif

	long long n, l, t;
	cin >> n >> l >> t;
	for (long long i = 1; i <= n; ++i) {
		cin >> x[i] >> w[i];
		if (w[i] == 2) w[i] = -1;
		endx[i] = ((x[i] + t * w[i]) % l + l) % l;
	}

	sort(endx + 1, endx + n + 1);

	long long c = 1;
	for (long long i = 1; i <= n; ++i) {
		if (w[i] == 1) {
			if (t < l - x[i]) continue;
			c = (c + (t - (l - x[i])) / l) % n + 1;
		} else {
			if (t < x[i] + 1) continue;
			c = (c + n - (t - x[i] - 1) / l % n - 2) % n + 1;
		}
	}

	for (long long i = c; i <= n; ++i) cout << endx[i] << '\n';
	for (long long i = 1; i < c; ++i) cout << endx[i] << '\n';

	return 0;
}