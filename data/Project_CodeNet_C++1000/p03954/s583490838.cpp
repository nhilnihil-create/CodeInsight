#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 100;

int n, a[N];
bool b[N];

bool ok(int c) {
	for (int i = 0; i < 2 * n - 1; i++)
		b[i] = (a[i] >= c);
	for (int d = 0; d < n; d++)
		if (b[n - 1 - d] == b[n - d])
			return b[n - d];
		else if (b[n - 1 + d - 1] == b[n - 1 + d])
			return b[n - 1 + d];
	return b[0];
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	for (int i = 0; i < 2 * n - 1; i++)
		cin >> a[i];
	int l = 1, r = 2 * n;
	while (r - l > 1) {
		int c = (l + r) >> 1;
		if (ok(c))
			l = c;
		else
			r = c;
	}
	cout << l;
}
