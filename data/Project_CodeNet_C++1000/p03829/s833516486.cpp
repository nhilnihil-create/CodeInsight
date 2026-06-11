#include <bits/stdc++.h>
using namespace std;

int n, pos;
long long ans, a, b, x;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> a >> b;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (i) {
			ans += min(a * (x - pos), b);
		}

		pos = x;
	}

	cout << ans << '\n';
	
	return 0;
}