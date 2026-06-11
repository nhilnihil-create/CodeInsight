#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define int ll

int get(int a, int b) {
	if (a == 0 || b == 0) {
		return 0;
	}
	if (a % b == 0) {
		return b * (a / b * 2 - 1);
	}
	int cnt = a / b;
	return b * cnt * 2 + get(b, a % b);
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, x;
	cin >> n >> x;
	if (2 * x == n) {
		cout << 3 * x << '\n';
		exit(0);
	}
	cout << n + get(max(x, n - x), min(x, n - x)) << '\n';
}