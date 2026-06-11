#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isEvenString(string s) {
	if (s.size() % 2 != 0) {
		return false;
	}
	int halfLength = s.size() / 2;
	for (int i = 0; i < halfLength; i++) {
		if (s[i] != s[halfLength + i]) {
			return false;
		}
	}
	return true;
}

int main() {

	string s; cin >> s;
	int ans;
	s.pop_back();
	while (true) {
		if (isEvenString(s)) {
			ans = s.size();
			break;
		}
		s.pop_back();
	}
	cout << ans << endl;
	return 0;
}