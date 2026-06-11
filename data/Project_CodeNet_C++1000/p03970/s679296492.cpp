#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	string s;
	cin >> s;

	string t = "CODEFESTIVAL2016";
	int res = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] != t[i]) { ++res; }
	}

	cout << res << endl;

	return 0;
}
