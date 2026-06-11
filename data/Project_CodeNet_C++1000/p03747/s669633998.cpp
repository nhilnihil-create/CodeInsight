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
	long long c = 1;
	for (long long i = 1; i <= n; ++i) {
		cin >> x[i] >> w[i];
		if (w[i] == 1) {
			c = (c + t / l - 1) % n + 1;
			endx[i] = x[i] + t % l;
			if (endx[i] >= l) {
				endx[i] -= l;
				c = c % n + 1;
			}
		} else {
			c = (c + n - t / l - 1) % n + 1;
			endx[i] = x[i] - t % l;
			if (endx[i] < 0) {
				endx[i] += l;
				c = (c + n - 2) % n + 1;
			}
		}
	}

	sort(endx + 1, endx + n + 1);

	for (long long i = c; i <= n; ++i) cout << endx[i] << '\n';
	for (long long i = 1; i < c; ++i) cout << endx[i] << '\n';

	return 0;
}