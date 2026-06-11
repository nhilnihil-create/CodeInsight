#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int h, w; cin >> h >> w;
	vector<string> s(h), res(h * 2);
	for (int i = 0; i < h; i++) cin >> s[i];
	for (int i = 0; i < 2 * h; i++) {
		res[i] = s[i / 2];
	}
	for (int i = 0; i < 2 * h; i++) cout << res[i] << '\n';
	return 0;
}
