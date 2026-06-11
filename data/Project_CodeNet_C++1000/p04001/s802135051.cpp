#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

int main() {
	string s;
	cin >> s;
	int n = s.size();
	long ans = 0;
	for (int i = 0; i < (1 << (n - 1)); i++) {
		long tmp = s[0] - '0';
		for (int j = 0; j < n - 1; j++) {
			if (i & (1 << j)) {
				ans += tmp;
				tmp = s[j + 1] - '0';
			} else {
				tmp = tmp * 10 + (s[j + 1] - '0');
			}
		}
		ans += tmp;
	}
	cout << ans << endl;
}