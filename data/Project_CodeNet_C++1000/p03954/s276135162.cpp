#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e6 + 10;

int n;
int a[N];

bool check(int m) {
	int b[N];
	for (int i = 1; i <= 2 * n - 1; i++) b[i] = (a[i] >= m);

	int l = 0, r = 0;

	for (int i = n; i >= 1; i--, l++) {
		if (i != 1) if (b[i] == b[i - 1]) break;
	}
	for (int i = n; i <= 2 * n - 1; i++, r++) {
		if (i != 2 * n - 1) if (b[i] == b[i + 1]) break;
	}

	int k = min(l, r);
	if (k < n) return b[n] ^ (k % 2);
	return b[1];
}

int main() {
	#ifdef LOCAL
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	#endif

	cin >> n;
	for (int i = 1; i <= 2 * n - 1; i++) scanf("%d", &a[i]);

	int l = 1, r = 2 * n - 1;
	while (l != r) {
		int m = (l + r + 1) / 2;
		if (check(m)) l = m;
		else r = m - 1;
	}
	cout << l << endl;

	return 0;
}
