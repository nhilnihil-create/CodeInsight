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
char s[105], t[105];
int main() {
	int n;
	scanf("%d%s%s", &n, s, t);
	string ss = s, tt = t;
	int ans = 2 * n;
	for (int i = 1; i <= n; ++i) {
		string sub = ss.substr(n - i, i);
		string sub2 = tt.substr(0, i);
		if (sub == sub2) ans = min(ans, 2 * n - i);
	}
	printf("%d\n", ans);
}
