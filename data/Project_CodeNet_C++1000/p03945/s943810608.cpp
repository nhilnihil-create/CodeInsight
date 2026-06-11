#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	string s;
	cin >> s;
	char c = s.at(0);
	ll ans = 1;
	for (int i = 1; i < s.length(); i++) {
		if (c == s.at(i))continue;
		else {
			c = s.at(i);
			ans++;
		}
	}
	cout << ans -1  << endl;
}