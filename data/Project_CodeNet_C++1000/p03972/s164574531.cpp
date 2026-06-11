#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
#include <bitset>
#include <cassert>
using namespace std;
typedef long long ll;




int main() {
	int W, H; cin >> W >> H;
	vector < pair<ll, int>> v;
	for (int i = 0; i < W; i++) {
		ll p; cin >> p;
		v.push_back({ p, 0 });
	}
	for (int i = 0; i < H; i++) {
		ll q; cin >> q;
		v.push_back({ q, 1 });
	}
	sort(v.begin(), v.end());
	ll ans = 0, h = 0, w = 0;
	for (int i = 0; i < H + W; i++) {
		ll r = v[i].first;
		int pq = v[i].second;
		if (pq == 0) {
			ans += (H + 1 - h)*r;
			w++;
		}
		else {
			ans += (W + 1 - w)*r;
			h++;
		}
	}
	cout << ans << endl;
	return 0;
}
