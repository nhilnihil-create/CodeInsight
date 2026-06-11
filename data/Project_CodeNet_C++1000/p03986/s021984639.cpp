#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin >> s;
	int l = s.size();
	int sc = 0, tc = 0;
	int ans = l;
	for (int i = 0; i < l;) {
		while (i != l && s[i] == 'S') {
			sc++;
			i++;
		}
		while (i != l && s[i] == 'T') {
			tc++;
			i++;
		}
		if (sc <= tc) {
			ans -= sc * 2;
			sc = tc = 0;
		} else {
			ans -= tc * 2;
			sc -= tc;
			tc = 0;
		}
	}
	cout << ans << endl;
	return 0;
}