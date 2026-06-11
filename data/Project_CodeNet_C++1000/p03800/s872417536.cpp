#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll n;
string s;

string calc_ans(string fs) {
	for (ll i = 1; i < n - 1; ++i) {
		if ((s[i] == 'o') ^ (fs[i] == 'W') ^ (fs[i - 1] == 'S')) {
			fs.push_back('W');
		}
		else {
			fs.push_back('S');
		}
	}
	return fs;
}

bool check_ans(string ans) {
	if ((s[n - 1] == 'o') ^ (ans[n - 1] == 'W') ^ (ans[n - 2] == ans[0]))return false;
	if ((s[0] == 'o') ^ (ans[0] == 'W') ^ (ans[n - 1] == ans[1]))return false;
	return true;
}

int main() {
	cin >> n >> s;
	for (string fs : {"SS", "SW", "WS", "WW"}) {
		string ans = calc_ans(fs);
		if (check_ans(ans)) {
			cout << ans << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}
