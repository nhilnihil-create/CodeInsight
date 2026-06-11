#include <bits/stdc++.h>
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
const int N = 3e5 + 5, M = 1e5 + 5;
int n, m;
struct Seg {
	int l, r;
} s[N];
vector<int> divi[M];
void sieve() {
	fw (i, 1, M) {
		for (int j = i; j < M; j += i) divi[j].pb(i);
	}
}
struct BIT {
	int t[M], n;
	void init(int _n) {
		n = _n;
		fw (i, 0, n + 1) t[i] = 0;
	}
	void add(int pos, int val) {
		pos++;
		for (; pos <= n; pos += (pos & (-pos))) t[pos] += val;
	}
	int get(int pos) {
		pos++;
		int ans = 0;
		for (; pos > 0; pos -= (pos & (-pos))) ans += t[pos];
		return ans;
	}
	int getRange(int l, int r) {
		int ans = get(r);
		if (l > 0) ans -= get(l - 1);
		return ans;
	}
} bit;
vector<int> leBounds[M];
int ans[M];
signed main() {
	#ifdef BLU
	in("blu.inp");
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	fw (i, 0, n) cin >> s[i].l >> s[i].r, s[i].l--, s[i].r--;
	bit.init(m);
	fw (i, 0, n) {
		bit.add(s[i].l, 1);
		leBounds[s[i].r].pb(s[i].l);
	}
	sieve();
	fw (i, 0, m) {
		fa (j, divi[i + 1]) {
			int lst = i - j + 1;
			ans[j] += bit.getRange(lst, i);
		}
		
		fa (j, leBounds[i]) bit.add(j, -1);
	}
	fw (i, 1, m + 1) cout << ans[i] << "\n";
	return 0;
}