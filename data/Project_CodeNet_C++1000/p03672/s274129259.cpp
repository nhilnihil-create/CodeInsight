#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	string s;
	cin >> s;
	int n = s.length();
	for (int i = 1; i < n; i++) {
		s = s.substr(0, s.length() - 1);
		if (s.length() % 2 == 1)continue;
		string sl, sr;
		sl = s.substr(0, s.length() / 2);
		sr = s.substr(s.length() / 2);
		if (sl == sr) {
			cout << s.length() << endl;
			return 0;
		}
	}
}