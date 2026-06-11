#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int main() {
	Int W, H;
	cin >> W >> H;
	vector<pair<Int, Int>> cost;
	for (int i = 0; i < W; ++i) {
		Int p; cin >> p;
		cost.emplace_back(p, 0);
	}
	for (int i = 0; i < H; ++i) {
		Int q; cin >> q;
		cost.emplace_back(q, 1);
	}

	sort(cost.begin(), cost.end());
	Int ans = 0;
	Int cntH = 0, cntW = 0;
	for (auto p : cost) {
		if (p.second) {
			ans += p.first * (W + 1 - cntW);
			++cntH;
		} else {
			ans += p.first * (H + 1 - cntH);
			++cntW;
		}
	}
	cout << ans << endl;

	return 0;
}
