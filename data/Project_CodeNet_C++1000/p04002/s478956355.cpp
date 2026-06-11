#include <bits/stdc++.h>
using namespace std;

int main() {
	auto inside = [](int a, int b, int alim, int blim) {
		return 0 <= a && a < alim && 0 <= b && b < blim;
	};
	int64_t h, w, n;
	cin >> h >> w >> n;
	pair<int, int> ps[n];
	for (auto &p : ps) {
		cin >> p.first >> p.second;
	}
	sort(ps, ps + n);
	int64_t ans[10]{};
	ans[0] = (h - 2) * (w - 2);
	map<pair<int, int>, int> map;
	for (auto &p : ps) {
		for (int dx = -1; dx <= 1; dx++) {
			for (int dy = -1; dy <= 1; dy++) {
				int nx = p.first + dx, ny = p.second + dy;
				if (nx <= 1 || ny <= 1 || h <= nx || w <= ny) {
					continue;
				}
				int count = 0;
				for (int ddx = -1; ddx <= 1; ddx++) {
					for (int ddy = -1; ddy <= 1; ddy++) {
						int nnx = nx + ddx, nny = ny + ddy;
						count += map[make_pair(nnx, nny)];
					}
				}
				ans[count]--;
				ans[count + 1]++;
			}
		}
		map[p]++;
	}
	for (auto &i : ans) {
		cout << i << endl;
	}
	return 0;
}