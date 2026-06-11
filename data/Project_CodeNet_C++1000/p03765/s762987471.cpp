#include <bits/stdc++.h>
using namespace std;

int main() {
	string _s, _t; cin >> _s >> _t;
	int sn = _s.size(), tn = _t.size();
	int s[sn] = {}, t[tn] = {};
	for(int i = 1; i <= sn; ++i) {
		s[i] = s[i - 1] + (_s[i - 1] == 'A' ? 1 : 2);
	}
	for(int i = 1; i <= tn; ++i) {
		t[i] = t[i - 1] + (_t[i - 1] == 'A' ? 1 : 2);
	}
	int q; cin >> q;
	while(q--) {
		int sl, sr; cin >> sl >> sr;
		int tl, tr; cin >> tl >> tr;
		int x = (s[sr] - s[sl - 1]) % 3;
		int y = (t[tr] - t[tl - 1]) % 3;
		if(x == y) {
			cout << "YES" << '\n';
		} else {
			cout << "NO" << '\n';
		}
	}
	return 0;
}