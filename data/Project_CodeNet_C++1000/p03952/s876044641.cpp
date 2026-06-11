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
	int n, x;
	scanf("%d%d", &n, &x);
	if (x == 1 || x == 2 * n - 1) printf("No\n");
	else {
		printf("Yes\n");
		vector<int> ans(2 * n);
		vector<bool> used(2 * n);
		ans[n] = x;
		ans[n - 1] = 1;
		ans[n + 1] = 2 * n - 1;
		used[1] = used[2 * n - 1] = used[x] = true;
		if (n > 2) {
			if (x == 2) ans[n - 2] = 2 * n - 2;
			else ans[n + 2] = 2;
			used[ans[n - 2]] = used[ans[n + 2]] = true;
		}
		int c = 1;
		for (int i = 1; i <= 2 * n - 1; ++i) {
			if (ans[i]) printf("%d\n", ans[i]);
			else {
				while (used[c]) ++c;
				printf("%d\n", c);
				++c;
			}
		}
	}
}
