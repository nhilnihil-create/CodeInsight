#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = 1e18;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	int n;
	cin >> n;
	int first;
	cin >> first;
	array<ll, 3> dp = {first, -INF, -INF};
	for (int i = 0; i < n-1; i++) {
		array<ll, 3> ndp = {-INF, -INF, -INF};
		char op;
		cin >> op;
		int num;
		cin >> num;
		if (op == '-') num = -num;
		for (int a = 0; a < 3; a++, num = -num) {
			if (dp[a] == -INF) continue;
			for (int b = a-1; b <= a+1; b++) {
				if (!(0 <= b && b < 3)) continue;
				if (op == '+' && b > a) continue;
				ndp[b] = max(ndp[b], dp[a] + num);
			}
		}
		swap(dp, ndp);
	}
	cout << *max_element(dp.begin(), dp.end()) << '\n';

	return 0;
}
