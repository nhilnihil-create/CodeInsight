#include <bits/stdc++.h>
using namespace std;

signed main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	long long s = 0, k = int64_t(n) * int64_t(n + 1) / 2LL;
	vector < int > a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		s += a[i];
	}
	if (s % k)
		cout << "NO\n";
	else {
		k = s / k;
		bool fucked_up = 0;
		for (int i = 0; i < n; ++i) {
			int t = k - a[(i + 1) % n] + a[i];
			fucked_up = fucked_up || (t < 0 || t % n);
		}
		if (fucked_up)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
}
