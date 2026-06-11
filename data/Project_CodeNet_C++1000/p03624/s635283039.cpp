#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

int main() {
   string s;
   cin >> s;
   string ans = "abcdefghijklmnopqrstuvwxyz";
   map<char,bool> m;
   for (int i = 0; i < (int)s.size(); ++i) {
		m[s[i]] = 1;
	}
	for (int i = 0; i < 26; ++i) {
		if (!m[ans[i]]) {
			cout << ans[i];
			return 0;
		}
	}
	cout << "None";
	return 0;
}

















