#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define sz(s) (int)s.size()

int main() {
	string s;
	cin >> s;
	rep(i, 0, sz(s)) if (s[i] == ',') s[i] = ' ';
	cout << s << endl;
}