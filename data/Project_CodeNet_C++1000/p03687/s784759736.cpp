#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	string s;
	cin >> s;
	set<char> st;
	rep(i, (int)s.size()) st.insert(s[i]);
	int ans = 100;
	for (auto a : st) {
		int cnt = 0;
		string t = s;
		rep(i, (int)t.size()) {
			bool ok = true;
			for (auto c : t) {
				if (c != a) ok = false;
			}
			if (ok) break;
			string u;
			rep(j, (int)t.size() - 1) {
				if (t[j] == a || t[j + 1] == a) {
					u.push_back(a);
				}
				else {
					u.push_back(t[j]);
				}
			}
			cnt++;
			t = u;
		}
		ans = min(ans, cnt);
	}
	cout << ans << endl;
	return 0;
}