// In the name of God

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	int c = 0;
	int ans = 0;
	for(int i = 0; i < s.length(); i++) {
		if(s[i] == 'T' && c) {
			c--;
			ans++;
		}
		if(s[i] == 'S') c++;
	}
	cout << (int)s.length() - 2 * ans;
	return 0;
}
