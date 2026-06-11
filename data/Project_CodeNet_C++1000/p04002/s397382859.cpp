#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int H, W;
int N;
set<pair<int, int>> painted;

set<pair<int, int>> used;
ll ans[10];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> H >> W >> N;
	for (int i = 0; i < N; i++) {
		int x, y; cin >> x >> y;
		painted.emplace(x, y);
	}

	for (auto p : painted) {
		for (int x = p.first - 1; x <= p.first + 1; x++) {
			for (int y = p.second - 1; y <= p.second + 1; y++) {
				if (x - 1 < 1 || x + 1 > H || y - 1 < 1 || y + 1 > W || used.count({x, y})) {
					continue;
				}
				used.emplace(x, y);
				int has = 0;
				for (int a = x - 1; a <= x + 1; a++) {
					for (int b = y - 1; b <= y + 1; b++) {
						has += painted.count({a, b});
					}
				}
				ans[has]++;
			}
		}
	}

	ans[0] = ll(H-2) * (W-2);
	for (int c = 1; c < 10; c++) {
		ans[0] -= ans[c];
	}

	for (int c = 0; c < 10; c++) {
		cout << ans[c] << '\n';
	}

	return 0;
}
