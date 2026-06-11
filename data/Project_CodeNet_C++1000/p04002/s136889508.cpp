# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <set>
# include <map>
# include <cmath>
# include <iomanip>
# include <functional>
# include <utility>
# include <stack>
# include <queue>
# include <list>
using namespace std;
using LL = long long;
constexpr long long MOD = 1000000000 + 7;
constexpr long long INF = 1000000000;
const double PI = acos(-1);

int main() {
	LL h, w;
	int n;
	LL ans[10] = {};
	map<pair<LL, LL>, int>val;

	cin >> h >> w >> n;
	ans[0] = (h - 2)*(w - 2);

	for (int i = 0; i < n; i++) {
		LL x, y;
		cin >> y >> x;
		y--, x--;
		for (int dx = -1; dx <= 1; dx++) {
			for (int dy = -1; dy <= 1; dy++) {
				LL nx = x + dx, ny = y + dy;
				if (0 < nx&&nx < w-1 && 0 < ny&&ny < h-1) {
					if (val.find(pair<LL, LL>(nx, ny)) == val.end()) {
						val[pair<LL, LL>(nx, ny)] = 1;
						ans[0]--;
						ans[1]++;
					}
					else {
						int num = val[pair<LL, LL>(nx, ny)] + 1;
						val[pair<LL, LL>(nx, ny)]++;
						ans[num - 1]--;
						ans[num]++;
					}
				}
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		cout << ans[i] << endl;
	}
}