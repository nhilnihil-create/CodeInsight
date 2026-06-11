#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	string s;
	cin >> s;
	ll k;
	cin >> k;
	for (int i = 0; i < s.length(); i++) {
		if (s.at(i) == 'a')continue;
		int x = 'z' - s.at(i) + 1;
		if (x <= k) {
			s.at(i) = 'a';
			k -= x;
		}
	}
	if (k == 0) {
		cout << s << endl;
		return 0;
	}
	if (k >= 26)k %= 26;
	s.at(s.length() - 1) = s.at(s.length() - 1) + k;
	cout << s << endl;
}