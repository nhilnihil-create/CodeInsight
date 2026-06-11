#include <bits/stdc++.h>

using namespace std;

int main() {

	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;

	string ss = s;
	string tt = t;

	while (ss != tt) {
		ss.erase(ss.begin());
		tt.erase(tt.end()-1);
	}

	cout << s.size()+t.size()-tt.size() << endl;

	return 0;
}