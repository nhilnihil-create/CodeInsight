#include <bits/stdc++.h>
using namespace std;

signed main () {
	int n, a, b;
	cin >> n >> a >> b;
	vector < long long > v(n);
	for (int i = 0; i < n; ++i) 
		cin >> v[i];
	sort(v.rbegin(), v.rend());
	long long m = 0;
	for (int i = 0; i < a; ++i)
		m += v[i];
	cout << fixed << setprecision(15) << double(m) / double(a) << '\n';
	long long l = lower_bound(v.begin(), v.end(), v[a - 1], greater<long long>()) - v.begin();
	long long r = upper_bound(v.begin(), v.end(), v[a - 1], greater<long long>()) - v.begin();
	long long len = r - l;
	vector < long long > c(len + 1, 1), wa(len + 1, 1);
	for (long long i = 1; i <= len; ++i) {
		c[i] = (c[i - 1] * (len - i + 1)) / i;
		wa[i] = wa[i - 1] + c[i];
	}
	if (v[a - 1] < v[0])
		cout << c[a - l] << '\n';
	else if (v[a - 1] == v[b - 1])
		cout << wa[b - l] - wa[a - l - 1] << '\n';
	else
		cout << wa[len] - wa[a - l - 1] << '\n';
}
