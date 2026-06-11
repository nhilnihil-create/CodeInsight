#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
#define ALL(v) (v).begin(),(v).end()
typedef long long LL;
const int INF = 1 << 25;
const LL MOD = 1000000007LL;
using namespace std;
typedef pair<int, int> P;
vector<int> pos[26];
map<P, int> cnt;
int main() {
	int H, W, N;
	cin >> H >> W >> N;
	rep(i, N) {
		int a, b;
		cin >> a >> b; a--; b--;
		for (int dx = -1; dx <= 1; dx++) {
			for (int dy = -1; dy <= 1; dy++) {
				int nx = b + dx, ny = a + dy;
				if (nx <= 0 || nx >= W-1 || ny <= 0 || ny >= H-1) continue;
				cnt[P(nx, ny)]++;
			}
		}
	}
	LL ans[10] = { 0 };
	LL sum = 0;
	for (auto p : cnt) ans[p.second]++;
	for (int i = 1; i <= 9; i++) sum += ans[i];
	ans[0] = (LL)(H-2)*(W-2) - sum;
	rep(i, 10) cout << ans[i] << endl;
}