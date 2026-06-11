#include <bits/stdc++.h>
using namespace std;

bool isSingleChar(string s) {
	for (int i = 1; i < s.size(); i++) {
		if (s[i] != s[0]) {
			return false;
		}
	}
	return true;
}

int main() {
	string S;
	cin >> S;
	int ans = INT_MAX;
	for (int i = 0; i < S.size(); i++) {  // S[i]に合わせに行く
		string s = S;
		int cnt = 0;
		while (!isSingleChar(s)) {
			for (int j = 0; j < s.size() - 1; j++) {
				s[j] = (s[j] == S[i] ? s[j] : s[j + 1]);
			}
			s.pop_back();
			cnt++;
		}
		ans = min(ans, cnt);
	}
	cout << ans << endl;
	return 0;
}
