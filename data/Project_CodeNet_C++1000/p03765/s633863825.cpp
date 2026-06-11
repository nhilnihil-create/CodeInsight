#include <bits/stdc++.h>
using namespace std;

signed main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s, t;
	cin >> s >> t;
	int n = s.size(), m = t.size(), q;
	vector < int > w_s(n + 1, 0), w_t(m + 1, 0);
	for (int i = 1; i <= n; ++i)
		w_s[i] = w_s[i - 1] + int(s[i - 1] - 'A') + 1;
	for (int i = 1; i <= m; ++i)
		w_t[i] = w_t[i - 1] + int(t[i - 1] - 'A') + 1;
	cin >> q;
	while (q--) {
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		if ((w_s[r1] - w_s[l1 - 1]) % 3 == (w_t[r2] - w_t[l2 - 1]) % 3)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
