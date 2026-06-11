#include <bits/stdc++.h>
#include <vector>

#define rep(i,n) for(int i=0;i<(n);++i)

using namespace std;

int main () {
	string s; cin >> s;
	string ans;

	rep(i, s.size()) {
		if (s[i] == '0') ans += '0';
		else if (s[i] == '1') ans += '1';
		else {
			if ( !ans.empty())  ans.pop_back();
		}
	}

	cout << ans << '\n';

	return 0;

}