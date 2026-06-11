#include <bits/stdc++.h>
using namespace std;
const int nm = 1e5;
int n, a[nm], b[nm];
long long s = 0, c;
int main() {
	cin >> n;
	c = (long long) n * (n + 1) / 2;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s += a[i];
	}
	if (s % c) {
		cout << "NO" << endl;
		return 0;
	}
	for (int i = 0; i < n; i++)
		b[i] = a[(i + 1) % n] - a[i] - s / c;
	for (int i = 0; i < n; i++)
		if (b[i] > 0 || b[i] % n) {
			cout << "NO" << endl;
			return 0;
		}
	cout << "YES" << endl;
}