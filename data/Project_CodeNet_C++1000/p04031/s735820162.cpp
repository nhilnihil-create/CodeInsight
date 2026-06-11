#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9 + 7;
const int N = 1e6 + 5;

int a[N];

int main() {
	int n, mx = -inf, mn = inf, cost = inf;
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		mn = min(a[i], mn);
		mx = max(a[i], mx);
	}
	for (int i = mn; i <= mx; i ++) {
		int sum = 0;
		for (int j = 1; j <= n; j ++) {
			sum += (a[j] - i) * (a[j] - i);
		}
		cost = min(cost, sum);
	}
	cout << cost << endl;
	return 0;
}