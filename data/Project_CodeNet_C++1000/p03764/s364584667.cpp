#include <bits/stdc++.h>

using namespace std;

void hawawa()
{
	int n, m;
	int mod = 1e9 + 7;
	cin >> n >> m;
	vector<long long> x(n);
	vector<long long> y(m);
	for (auto&& i : x) {
		cin >> i;
	}
	for (auto&& i : y) {
		cin >> i;
	}
	long long xsize = 0;
	for (int i = 0; i < n; i++) {
		xsize += i * x[i];
		xsize %= mod;
		xsize -= (n - 1 - i) * x[i];
		xsize %= mod;
	}
	long long ysize = 0;
	for (int i = 0; i < m; i++) {
		ysize += i * y[i];
		ysize %= mod;
		ysize -= (m - 1 - i) * y[i];
		ysize %= mod;
	}
	long long ans = xsize * ysize;
	ans %= mod;
	cout << ans << "\n";

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	hawawa();
	return 0;
}
