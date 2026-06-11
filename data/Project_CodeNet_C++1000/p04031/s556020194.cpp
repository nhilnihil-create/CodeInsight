#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	long n, ans = 999999999;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a+n);
	for (int i = a[0]; i <= a[n - 1]; i++) {
		long p = 0;
		for (int j = 0; j < n; j++) {
			p += (i - a[j]) * (i - a[j]);
		}
		ans = min(ans, p);
	}
	cout << ans;
}