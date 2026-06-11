#include <bits/stdc++.h>
using namespace std;

bool iseven(string s) {
	if (s.size() % 2 == 1)
		return false;
	return s.substr(0, s.size() / 2) == s.substr(s.size() / 2, s.size() / 2);
}

int main() {
	string s;
	cin >> s;
	for (int i = s.size() - 1;; i--) {
		if (iseven(s.substr(0, i))) {
			cout << i << endl;
			break;
		}
	}
	return 0;
}
