#include <bits/stdc++.h>
using namespace std;
//#define cerr if (false) cerr
#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define dbv(v) cerr << #v << "="; for (auto _x : v) cerr << _x << ", "; cerr << endl
#define dba(a, n) cerr << #a << "="; for (int _i = 0; _i < (n); ++_i) cerr << a[_i] << ", "; cerr << endl
template <typename A, typename B>
ostream& operator<<(ostream& os, const pair<A, B>& x) {
	return os << "(" << x.first << "," << x.second << ")";
}
typedef long long ll;
typedef long double ld;
int main() {
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	vector<int> H(n);
	for (int i = 0; i < n; ++i) scanf("%d", &H[i]);
	int lo = 1, hi = 1e9;
	while (lo < hi) {
		int m = (lo + hi) >> 1;
		ll tot = 0;
		for (int i = 0; i < n; ++i) {
			ll lef = H[i] - (ll)m * b;
			if (lef < 0) continue;
			tot += (lef + (a - b - 1)) / (a - b);
		}
		if (tot <= m) hi = m;
		else lo = m + 1;
	}
	printf("%d\n", lo);
}