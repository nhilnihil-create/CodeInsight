#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	vector <long long> a(n+1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	vector <long long> sp(n+1), s(n+1);

	for (int i = 1; i <= n; ++i) {
		if(a[i] >= 0)sp[i] += sp[i-1] + a[i];
		else sp[i] = sp[i-1];

		s[i] += s[i-1] + a[i];
	}
	long long ans = 0;
	for (int i = 1; i <= n - k + 1; ++i) {
		ans = max(ans, sp[i-1] + max(0LL, s[i+k-1] - s[i-1]) + sp[n] - sp[i+k-1]);
	}
	cout << ans << '\n';
}