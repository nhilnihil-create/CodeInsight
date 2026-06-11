#include <bits/stdc++.h>
using namespace std;

signed main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s;
	cin >> s;
	if (bool(int(s.size()) & 1) ^ (s.front() == s.back()))
		cout << "First\n";
	else
		cout << "Second\n";
}
