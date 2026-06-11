#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

long long f[N], a[N], w[N], l, n, t;


int main() {
	cin >> n >> l >> t;
	long long one = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> w[i];
		if (w[i] == 1) {
			f[i] = (a[i] + t) % l;
			if (l - a[i] <= t) {
				one += 1 + (t - (l - a[i])) / l;
			}
		}
		else {
			f[i] = (((a[i] - t) % l) + l) % l;
			if (t > a[i])
				one -= 1 + (t - (a[i] + 1)) / l;
		}
	}
	sort(f, f + n);
	one = (((one % n) + n) % n);
	for (int i = one; i < n; i++)
		cout << f[i] << endl;
	for (int i = 0; i < one; i++)
		cout << f[i] << endl;
	return 0;
}
