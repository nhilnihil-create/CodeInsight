#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	string s; cin >> s;
	string ans = "";
	for (int i = 0; i < s.size(); i++) {
		if (i % 2 == 0) {
			ans += s[i];
		}
	}
	cout << ans << endl;
	return 0;
}