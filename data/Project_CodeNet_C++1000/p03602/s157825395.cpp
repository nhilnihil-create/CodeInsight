#include <bits/stdc++.h>
#define int long long
#define bp __builtin_popcountll
#define pb push_back
#define in(s) freopen(s, "r", stdin);
#define out(s) freopen(s, "w", stdout);
#define inout(s, end1, end2) freopen((string(s) + "." + end1).c_str(), "r", stdin),\
		freopen((string(s) + "." + end2).c_str(), "w", stdout);
#define fi first
#define se second
#define bw(i, r, l) for (int i = r - 1; i >= l; i--)
#define fw(i, l, r) for (int i = l; i < r; i++)
#define fa(i, x) for (auto i: x)
using namespace std;
const int mod = 1e9 + 7, inf = 1061109567;
const long long infll = 4557430888798830399;
const int N = 305;
int n, a[N][N], b[N][N];
signed main() {
	#ifdef BLU
	in("blu.inp");
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	fw (i, 0, n) fw (j, 0, n) cin >> a[i][j];
	int ans = 0;
	memset(b, 63, sizeof b);
	fw (i, 0, n) fw (j, 0, n) if (i != j) {
		bool haveMid = 0;
		fw (k, 0, n) if (k != i && k != j) if (a[i][k] + a[k][j] == a[i][j]) haveMid = 1;
		if (!haveMid) ans += a[i][j], b[i][j] = a[i][j];
	}
	fw (i, 0, n) b[i][i] = 0;
	fw (k, 0, n) fw (i, 0, n) fw (j, 0, n) b[i][j] = min(b[i][j], b[i][k] + b[k][j]);
	fw (i, 0, n) fw (j, 0, n) if (a[i][j] != b[i][j]) {
		cout << "-1";
		return 0;
	}
	cout << ans / 2;
	return 0;
}