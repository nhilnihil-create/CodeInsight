#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
typedef long long lint;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef pair<lint, lint> pll;
typedef unsigned long long ulint;
#define endl '\n'
#define fst first
#define sed second
#define pb push_back
#define mp make_pair
#define rint register int
#define SZ(x) (int((x).size()))
#define all(x) (x).begin(), (x).end()
#define reveal(x) cerr << #x << " = " << (x) << endl
#define rep(it, f, e) for (rint it = (f); it <= (e); ++it)
#define per(it, f, e) for (rint it = (f); it >= (e); --it)
#define repe(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)
const int MAXN = 5050;
int a[MAXN], dp1[MAXN][MAXN], dp2[MAXN][MAXN];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	rep (i, 1, n) {
		cin >> a[i];
		a[i] = min(a[i], k); 
	}
	dp1[0][0] = 1;
	rep (i, 0, n - 1) {
		rep (j, 0, k - 1) if (dp1[i][j]) {
			dp1[i + 1][j] = 1;
			if (j + a[i + 1] < k) {
				dp1[i + 1][j + a[i + 1]] = 1;
			}
		}
	}
	dp2[n + 1][0] = 1;
	per (i, n + 1, 2) {
		rep (j, 0, k - 1) if (dp2[i][j]) {
			dp2[i - 1][j] = 1;
			if (j + a[i - 1] < k) {
				dp2[i - 1][j + a[i - 1]] = 1;
			}
		}
	}
	rep (i, 1, n + 1) {
		rep (j, 1, k) {
			dp2[i][j] += dp2[i][j - 1];
		}
	}
	int ans = 0;
	rep (i, 1, n) {
		int l = max(0, k - a[i]), r = k - 1;
		bool flag = true;
		rep (j, 0, k - 1) if (dp1[i - 1][j]) {
			int nl = max(0, l - j), nr = r - j;
			if (dp2[i + 1][nr] - (nl ? dp2[i + 1][nl - 1] : 0)) flag = false;
		}
		ans += flag;
	}
	cout << ans << endl;
	return 0;
}