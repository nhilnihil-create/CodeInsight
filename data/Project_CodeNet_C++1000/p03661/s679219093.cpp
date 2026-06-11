#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	long long s = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s += a[i];
	}
	long long s1 = 0, res = LONG_MAX;
	for (int i = 0; i < n - 1; i++) {
		s1 += a[i];
		res = min(res, abs(s1 - (s - s1)));
	}
	cout << res;
	return 0;
}