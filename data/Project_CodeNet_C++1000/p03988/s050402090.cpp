#include <bits/stdc++.h>
#define bp __builtin_popcountll
#define pb push_back
#define in(s) freopen(s, "r", stdin);
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
const int N = 105;
int n, mn = inf, a[N], cnt[N], mx = -inf;
void bad() {
	cout << "Impossible";
	exit(0);
}
void good() {
	cout << "Possible";
	exit(0);
}
signed main() {
	#ifdef BLU
	in("blu.inp");
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	fw (i, 0, n) cin >> a[i], mn = min(mn, a[i]), mx = max(mx, a[i]), cnt[a[i]]++;
	fw (i, 0, n) if (a[i] > 2 * mn) bad();
	bool startbad = 0;
	if (n == 2 && cnt[1] == 2) good();
	if (cnt[1] > 1) bad();
	fw (i, mn, 2 * mn + 1) {
		if (cnt[i] == 0) startbad = 1;
		if (startbad && cnt[i] > 0) bad();
	}
	//Missing case: cnt[1 -> (mx + 1) / 2] > 2.
	fw (i, mn, (mx + 1) / 2 + 1) if (cnt[i] > 2) bad();
	if (!(mx & 1) && cnt[mx >> 1] > 1) bad();
	good();
	return 0;
}