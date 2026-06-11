#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
	int H, W;
	cin >> H >> W;

	vector<string> ans(2 * H);
	for (int i = 0; i < 2 * H; i += 2) {
		cin >> ans[i];
		ans[i + 1] = ans[i];
	}

	for (auto o : ans) {
		cout << o << endl;
	}
	return 0;
}
