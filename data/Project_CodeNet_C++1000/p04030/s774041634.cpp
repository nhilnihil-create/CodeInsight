#include<iostream>

using namespace std;

int main() {
	string s;
	cin >> s;
	string ans;
	for (int i = 0;i < s.length();i++) {
		if (s[i] == '0') {
			ans += "0";
		}
		if (s[i] == '1') {
			ans += "1";
		}
		if (s[i] == 'B') {
			if (ans.length() >= 1) {
				ans = ans.substr(0, ans.length() - 1);
			}
		}
	}
	cout << ans << endl;
}