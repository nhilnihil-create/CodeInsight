#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
const double PI = 3.141592653589793238;
const double EPS = 1e-10;
typedef pair<int, int> P;
int main() {
	ll H, W, N;
	cin >> H >> W >> N;
	set<P> S;
	set<P> T;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> y >> x;
		x--; y--;
		S.insert(P(x, y));
		for (int dx = -1; dx <= 1; dx++) {
			for (int dy = -1; dy <= 1; dy++) {
				int nx = x + dx;
				int ny = y + dy;
				if (1 > nx || nx >= W - 1 || 1 > ny || ny >= H - 1) continue;
				T.insert(P(nx, ny));
			}
		}
	}
	ll ans[10] = {};
	ll sum = 0;
	for (auto p : T) {
		int x = p.first, y = p.second;
		int cnt = 0;
		for (int dx = -1; dx <= 1; dx++) {
			for (int dy = -1; dy <= 1; dy++) {
				if (S.find(P(x + dx, y + dy)) != S.end()) cnt++;
			}
		}
		ans[cnt]++;
		sum++;
	}
	ans[0] = (H - 2)*(W - 2) - sum;
	for (int i = 0; i < 10; i++) {
		cout << ans[i] << endl;
	}
}
