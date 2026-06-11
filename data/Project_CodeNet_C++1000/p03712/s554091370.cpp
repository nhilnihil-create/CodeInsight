#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
	int H, W;
	cin >> H >> W;

	string bar = "";
	for (int i = 0; i < W+2; ++i) {
		bar += '#';
	}

	vector<string> ans(H+2);
	for (int i = 0; i < H+2; ++i) {
		if (i == 0 || i == H + 1) {
			ans[i] = bar;
			continue;
		}

		string a;
		cin >> a;

		string tmp = '#' + a + '#';
		ans[i] = tmp;
	}

	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << endl;
	}
	return 0;
}
