#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
string s, t;
int S[N], T[N], n, m;

main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> s >> t;
	n = s.size(); s = ' ' + s;
	m = t.size(); t = ' ' + t;
	for(int i = 1; i <= n; ++i) S[i] = S[i - 1] + (s[i] == 'A' ? 1 : 2);
	for(int i = 1; i <= m; ++i) T[i] = T[i - 1] + (t[i] == 'A' ? 1 : 2);
	int test;
	cin >> test;
	while(test--) {
		int x, y, u, v;
		cin >> x >> y >> u >> v;
		if((S[y] - S[x - 1]) % 3 == (T[v] - T[u - 1]) % 3) {
			cout << "YES\n";
		}
		else cout << "NO\n";
	}
}
