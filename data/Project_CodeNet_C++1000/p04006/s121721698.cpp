#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//https://atcoder.jp/contests/agc004/tasks/agc004_b

const int nm = 2e3;
int n;
ll x, a[nm][nm], temp, ans = 2e12;

int main() {
	cin >> n >> x;
	for (int i = 0; i < n; ++i)
		cin >> a[0][i];
	for (int i = 1; i < n; ++i)
		for (int j = 0; j < n; ++j)
			a[i][j] = min(a[i - 1][(j + n - 1) % n], a[0][j]);
	for (int i = 0; i < n; ++i) {
		temp = x * i;
		for (int j = 0; j < n; ++j)
			temp += a[i][j];
		ans = min(ans, temp);
	}
	cout << ans << endl;
}
