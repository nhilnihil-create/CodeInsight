#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = a; i <= b; i++)

string s, t;
int q, a, b, c, d, pres[100050], pret[100050];

int main() {
	cin >> s >> t >> q;
	s = " " + s;
	t = " " + t;
	FOR(i, 1, s.length()-1) {
		pres[i] = pres[i-1] + (s[i] == 'A' ? 1 : 2);
		pres[i] %= 3;
	}
	FOR(i, 1, t.length()-1) {
		pret[i] = pret[i-1] + (t[i] == 'A' ? 1 : 2);
		pret[i] %= 3;
	}
	while (q--) {
		cin >> a >> b >> c >> d;
		if ((pres[b] - pres[a-1] + 3) % 3 == (pret[d] - pret[c-1] + 3) % 3) cout << "YES\n";
		else cout << "NO\n";
	}
}
