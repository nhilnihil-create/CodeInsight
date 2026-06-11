#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
int h, w, n;
map <ii, bool> mp, ex;
long long ans[11];

void solve(int x, int y) {
	if (ex.count(ii(x, y))) return;
	if (x <= 0 || y <= 0 || x + 2 > h || y + 2 > w) return;
	ex[ii(x, y)] = true;
	int res = 0;
	for (int i = 0; i <= 2; ++i) for (int j = 0; j <= 2; ++j) {
		if (mp.count(ii(x + i, y + j))) ++res;
	}
	++ans[res];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> h >> w;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int x, y; cin >> x >> y;
		mp[ii(x, y)] = 1;
	}

	for (map<ii, bool>::iterator it = mp.begin(); it != mp.end(); ++it) {
		int x = (it -> first).first, y = (it -> first).second;
		solve(x - 2, y - 2);
		solve(x - 2, y - 1);
		solve(x - 2, y);
		solve(x - 1, y - 2);
		solve(x - 1, y - 1);
		solve(x - 1, y);
		solve(x, y - 2);
		solve(x, y - 1);
		solve(x, y);
	}

	long long sum = 0;
	for (int i = 0; i <= 9; ++i) sum += ans[i];
	ans[0] += 1LL * (h-2) * (w-2) - sum;

	for (int i = 0; i <= 9; ++i) printf("%lld\n", ans[i]);
}