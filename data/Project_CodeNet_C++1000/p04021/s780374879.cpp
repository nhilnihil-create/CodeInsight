#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 100;

int n, a[N], b[N], c[N];

int same() {
	int p = 0;
	int res = 0;
	for (int i = 1; i < n; i += 2)
		a[i] = a[i - 1];
	sort(a, a + n);
	for (int i = 0; i < n; i += 2) {
		while (p < n && a[p] < b[i])
		p++;
		if (p < n && a[p] == b[i]) {
			res++;
			p += 2;
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b, b + n);
	cout << ((n + 1) >> 1) - same();
}
