#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	
	string s; cin >> s;
	string ans = "";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0') {
			ans += "0";
		}
		else  if (s[i] == '1') {
			ans += "1";
		}
		else {
			if (ans.size() != 0) {
				ans.pop_back();
			}
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i];
	}
	return 0;
}