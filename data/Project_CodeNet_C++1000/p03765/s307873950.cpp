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
char S[100005], T[100005];
int main() {
	scanf("%s%s", S, T);
	int n = strlen(S), m = strlen(T);
	vector<int> ss(n + 1), tt(m + 1);
	for (int i = 0; i < n; ++i) ss[i + 1] = ss[i] + 1 + (S[i] == 'B');
	for (int i = 0; i < m; ++i) tt[i + 1] = tt[i] + 1 + (T[i] == 'B');
	int q;
	scanf("%d", &q);
	while (q--) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		printf((ss[b] - ss[a - 1]) % 3 == (tt[d] - tt[c - 1]) % 3 ? "YES\n" : "NO\n");
	}
}
