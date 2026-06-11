#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	string s, t; cin >> s >> t;
	vector<int> ps(s.size() + 1), pt(t.size() + 1);
	for (int i = 1; i <= s.size(); i++) {
		ps[i] = ps[i-1] + (s[i-1] == 'A');
	} 
	for (int i = 1; i <= t.size(); i++) {
		pt[i] = pt[i-1] + (t[i-1] == 'A');
	} 

	int q; cin >> q;
	while (q--) {
		int a, b, c, d; cin >> a >> b >> c >> d;

		int psa = (ps[b] - ps[a-1]) % 3;
		int psb = ((b - a + 1) - psa) % 3;

		int pta = (pt[d] - pt[c-1]) % 3;
		int ptb = ((d - c + 1) - pta) % 3;

		if ((2*psa + psb) % 3 == (2*pta + ptb) % 3) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

	return 0;
}
