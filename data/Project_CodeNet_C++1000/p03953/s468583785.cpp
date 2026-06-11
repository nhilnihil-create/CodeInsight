#include <iostream>
#include <algorithm>

using namespace std;

int x[100001], d[100001];
int a[100001], pos[70][100001];

int main() {
	int n, m;
	long long k;

	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> x[i];

	cin >> m >> k;
	for (int i = 1; i <= m; ++i) cin >> a[i];

	for (int i = 1; i < n; ++i) d[i] = i;

	for (int i = 1; i <= m; ++i)
		swap(d[a[i] - 1], d[a[i]]);
	for (int i = 1; i < n; ++i)
		pos[0][d[i]] = i;
	
	for (int i = 1; i <= 61; ++i)
		for (int j = 1; j < n; ++j)
			pos[i][j] = pos[i - 1][pos[i - 1][j]];

	for (int i = 1; i < n; ++i) {
		int p = i;
		long long t = k;
		for (int j = 61; j >= 0; --j)
			if (t >= (1LL << j)) {
				t -= (1LL << j);
				p = pos[j][p];
			}
		d[p] = x[i + 1] - x[i];
	}

	long long sum = x[1];
	cout << sum << '\n';
	for (int i = 1; i < n; ++i) {
		sum += d[i];
		cout << sum << '\n';
	}

	return 0;
}