#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
	int w, h, n;
	cin >> w >> h >> n;
	int x, y, a;
	int x1=0, x2=w, y1=0, y2=h;
	rep(i, n) {
		cin >> x >> y >> a;
		if (a == 1) {
			x1 = max(x1, x);
		}
		else if (a == 2) {
			x2 = min(x2, x);
		}
		else if (a == 3) {
			y1 = max(y1, y);
		}
		else {
			y2 = min(y2, y);
		}
	}
	if (x1 >= x2 || y1 >= y2)cout << 0 << endl;
	else cout << (x2 - x1) * (y2 - y1) << endl;

	return 0;
}

