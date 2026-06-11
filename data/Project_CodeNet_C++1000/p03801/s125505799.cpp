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
const int N = 1e5 + 5;
int n, a[N], ans[N];
map<int, int> mnPile, cntPile;
signed main() {
	#ifdef BLU
	in("blu.inp");
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	vector<int> v;
	fw (i, 0, n) {
		cin >> a[i];
		v.pb(a[i]);
		if (!mnPile.count(a[i])) mnPile[a[i]] = inf;
		mnPile[a[i]] = min(mnPile[a[i]], i);
		cntPile[a[i]]++;
	}
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	reverse(v.begin(), v.end());
	int curMn = inf, curCnt = 0;
	fw (i, 0, v.size()) {
		curCnt += cntPile[v[i]];
		curMn = min(curMn, mnPile[v[i]]);
		
		int nxt = 0;
		if (i < v.size() - 1) nxt = v[i + 1];
		ans[curMn] += (v[i] - nxt) * curCnt;
	}
	fw (i, 0, n) cout << ans[i] << "\n";
	return 0;
}