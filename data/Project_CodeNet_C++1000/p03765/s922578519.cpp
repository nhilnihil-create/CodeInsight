#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s, t; cin >> s >> t;
	int n = s.size(), m = t.size();
	vector <int> a(n + 1, 0), b(m + 1, 0);
	for(int i = 1; i <= n; i++) {
		a[i] = a[i - 1] + (s[i - 1] - 'A');
	}
	for(int i = 1; i <= m; i++) {
		b[i] = b[i - 1] + (t[i - 1] - 'A');
	}
	int q; cin >> q;
	for(int i = 1; i <= q; i++) {
		int l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2;
		int xx = a[r1] - a[l1 - 1] - (r1 - l1 + 1 - (a[r1] - a[l1 - 1]));
		xx %= 3;
		xx = (xx + 3) % 3;
		int yy = b[r2] - b[l2 - 1] - (r2 - l2 + 1 - (b[r2] - b[l2 - 1]));
		yy %= 3;
		yy = (yy + 3) % 3;
		cout << ((xx ^ yy) ? "NO" : "YES") << endl;
	}
}