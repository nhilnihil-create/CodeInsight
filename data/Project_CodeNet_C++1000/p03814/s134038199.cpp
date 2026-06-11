#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
	string s;
	cin >> s;

	int ans = 0;
	int cnt = 0;
	bool in = false;

	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == 'A' && in == false) {
			cnt = 1;
			in = true;
		}
		else if (s[i] == 'Z' && in == true) {
			ans = max(ans, cnt);
		}

		if (in) {
			cnt++;
		}
	}
	cout << ans << endl;
	return 0;
}