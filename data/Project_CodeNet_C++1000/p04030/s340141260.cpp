#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	string s;
	cin >> s;
	string ans;
	rep(i, (int)s.size()) {
		if (s[i] == 'B') {
			if(!ans.empty()) ans.pop_back();
		}
		else ans += s[i];
	}
	cout << ans << endl;
	return 0;
}