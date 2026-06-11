#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
string s, t;
int ps[N], pt[N], n, m, q;

main() {
	
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> s >> t;
	n = s.size(); m = t.size(); 
	s = ' ' + s;
	for(int i = 1; i <= n; ++i) {
		int tmp = 1;
		if(s[i] == 'B') tmp++;
	 	ps[i] = ps[i - 1] + tmp;
	}
	t = ' ' + t;
	for(int i = 1; i <= m; ++i) {
		int tmp = 1;
		if(t[i] == 'B') tmp++;
		pt[i] = pt[i - 1] + tmp;
	}
	cin >> q;
	while(q--) {
		int x, y, u, v;
		cin >> x >> y >> u >> v;
		if((ps[y]-ps[x - 1]) % 3 == (pt[v]-pt[u - 1]) % 3) cout << "YES\n";
		else cout << "NO\n";
	}
}