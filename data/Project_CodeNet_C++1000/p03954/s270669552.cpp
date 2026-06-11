#include <bits/stdc++.h>
using namespace std;

int n, N, a[200005], b[200005], c[200005], l, r, m, fp;

bool ShAM() {
	for(int i = 1; i <= N; ++i) c[i] = 0;
	for(int i = 2; i <= N; ++i) {
		if(b[i] == b[i - 1]) {
			c[i] = c[i - 1] = 1;
		}
	}
	int k = 1e9, t = 1e9;
	for(int i = N / 2 + 1; i <= N; ++i) {
		if(c[i]) {
			k = i - (N / 2 + 1);
			break;
		}
	}
	for(int i = N / 2; i >= 1; --i) {
		if(c[i]) {
			t = N / 2 + 1 - i;
			break;
		}
	}
	return (k == 0) ? b[N / 2 + 1] : (k > n - 1 && t > n - 1) ? ((bool)b[N / 2 + 1] ^ (bool)(n & 1 ^ 1)) : (k == t) ? (b[N / 2 + 1 + k] && b[N / 2 + 1 - t]) ? 1 : (!b[N / 2 + 1 + k] && !b[N / 2 + 1 - t]) ? 0 : ((bool)b[N / 2 + 1] ^ (bool)(k & 1 ^ 1)) : (k < t) ? (bool)b[N / 2 + 1 + k] : (bool)b[N / 2 + 1 - t];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n; N = 2 * n - 1;
	for(int i = 1; i <= N; ++i) {
		cin >> a[i];
	}
	l = 1;
	r = N;
	while(l <= r) {
		m = (l + r) / 2;
		for(int i = 1; i <= N; ++i) {
			if(a[i] <= m) b[i] = 1;
			else b[i] = 0;
		}
		if(ShAM()) {
			fp = m;
			r = m - 1;
		} else {
			l = m + 1;
		}
	}
	cout << fp << endl;
	return 0;
}