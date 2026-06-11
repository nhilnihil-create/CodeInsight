#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<cmath>
#include<list>
#include<set>
#include<map>

using namespace std;
long long MOD = 1000000007LL;
const double PI = 3.14159265358979323846;
#undef INT_MIN
#undef INT_MAX
#define INT_MIN -2147483648
#define INT_MAX 2147483647
#define endl "\n"

void dfs(int x, int y, int th, int amount, map<int, int> &mp) {
	if (mp[amount] == 1)return;
	if (th < amount) {
		return;
	}
	else if (amount <= th) {
		mp[amount] = 1;
	}

	dfs(x, y, th, amount + x, mp);
	dfs(x, y, th, amount + y, mp);
	return;
}

int main() {
	int A, B, C, D, E, F;
	cin >> A >> B >> C >> D >> E >> F;

	map<int, int> water;
	dfs(100 * A, 100 * B, F, 0, water);

	pair<int, int> ans;
	double maxCon = 0;
	for (auto _w : water) {
		if (_w.second == 0)continue;
		double w = _w.first;

		for (double i = 0;; ++i) {
			double _s = C * i;
			for (double j = 0;; ++j) {
				double s = _s + D * j;
				if ((E * w / 100.0) + 1 <= s) {
					break;
				}
				if (w + s <= F && maxCon < 100.0 * s / (w + s)) {
					ans = make_pair((int)w + s, (int)s);
					maxCon = 100.0 * s / (w + s);
				}
			}
			if ((E * w / 100.0) + 1 <= _s) {
				break;
			}
		}

	}

	if (ans.first == 0 && ans.second == 0) {
		for (auto x : water) {
			if (x.first != 0) {
				cout << x.first << " " << 0 << endl;
				return 0;
			}
		}
	}
	cout << ans.first << " " << ans.second << endl;
	return 0;
}
