#include <bits/stdc++.h>
using namespace std;

inline
int gcd(int x, int y) {
	if (x % y == 0) return y;
	else return gcd(y, x % y);
}

int main() {
	int n, k, g; cin >> n >> k >> g;
	int maxi = g;
	n--;
	while (n--) {
		int a; cin >> a;
		g = gcd(g, a);
		maxi = max(maxi, a);
	}
	cout << ((k % g == 0 && k <= maxi) ? "POSSIBLE" : "IMPOSSIBLE") << '\n';
	return 0;
}
