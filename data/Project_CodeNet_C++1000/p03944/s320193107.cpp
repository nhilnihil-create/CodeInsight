#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void solve() {
	int h, w, n;
	cin >> w >> h >> n;
	vector<tuple<int, int, int>> v(n);
	rep(i,n) {
		int x, y, a;
		cin >> x >> y >> a;
		v[i] = tuple<int, int, int> (x, y, a);
	}
	int lx = 0;
	int rx = w;
	int dy = 0;
	int uy = h;
	rep(i,n) {
		int x = get<0>(v[i]);
		int y = get<1>(v[i]);
		int a = get<2>(v[i]);
		if (a == 1) {
			lx = max(lx, x);
		} else if (a == 2) {
			rx = min(rx, x);
		} else if (a == 3) {
			dy = max(dy, y);
		} else {
			uy = min(uy, y);
		}
	}
	int x = rx - lx;
	int y = uy - dy;
	if (x <= 0 || y <= 0) {
		cout << 0 << endl;
	} else {
		cout << x * y << endl;
	}
}

int main() {
	solve();
	return 0;
}