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
const int N = 1e5 + 5;
string s, t;
int pres[N], pret[N];
signed main() {
	#ifdef BLU
	in("blu.inp");
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> s >> t;
	fw (i, 0, s.length()) {
		pres[i] = i ? pres[i - 1] : 0;
		if (s[i] == 'A') pres[i]++;
		else pres[i] += 2;
	}
	fw (i, 0, t.length()) {
		pret[i] = i ? pret[i - 1] : 0;
		if (t[i] == 'A') pret[i]++;
		else pret[i] += 2;
	}
	
	int q;
	cin >> q;
	while (q--) {
		int a1, b1, c1, d1;
		cin >> a1 >> b1 >> c1 >> d1;
		a1--, b1--, c1--, d1--;
		
		int sum1 = pres[b1] - (a1 ? pres[a1 - 1] : 0), sum2 = pret[d1] - (c1 ? pret[c1 - 1] : 0);
		if (sum1 % 3 == sum2 % 3) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
