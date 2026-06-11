#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <bitset>
#include <functional>
using namespace std;

typedef long long ll;

pair<int, int> ab[100003];
ll cnt[13];
set<pair<int, int>> s;

int main() {
	ll h, w; int n; cin >> h >> w >> n;
	for (int i = 0; i < n; ++i) {
		cin >> ab[i].first >> ab[i].second;
		--ab[i].first; --ab[i].second;
		s.insert(ab[i]);
	}

	for (int t = 0; t < n; ++t) {
		int posi = ab[t].first - 2, posj = ab[t].second - 2;
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				if (!(0 <= posi + i && posi + i + 2 < h && 0 <= posj + j && posj + j + 2 < w)) continue;
				int c = 0;
				for (int ii = 0; ii < 3; ++ii) {
					for (int jj = 0; jj < 3; ++jj) {
						c += s.count({ posi + i + ii, posj + j + jj });
					}
				}
				++cnt[c];
			}
		}
	}
	ll sum = 0;
	for (ll i = 1; i <= 9; ++i) {
		cnt[i] /= i;
		sum += cnt[i];
	}
	cnt[0] = (h - 2)*(w - 2) - sum;
	for (int i = 0; i <= 9; ++i) cout << cnt[i] << endl;
	return 0;
}