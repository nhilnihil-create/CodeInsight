#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	string s; cin >> s;
	int need_left = 0;
	int pointer = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') ++pointer;
		else {
			if (pointer == 0) ++need_left;
			else --pointer;
		}
	}
	int need_right = pointer;
	string ans = "";
	for (int i = 0; i < need_left; i++) {
		ans += '(';
	}
	ans += s;
	for (int i = 0; i < need_right; i++) {
		ans += ')';
	}
	cout << ans << endl;
	return 0;
}