#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAX = 100005;

int main() {
	int n, m;
	cin >> n >> m;
	vector<pii> p(n), c(n);
	rep(i, n) cin >> p[i].first >> p[i].second;
	rep(i, m) cin >> c[i].first >> c[i].second;
	rep(i, n) {
		int mn = 1e9, ans = 0;
		rep(j, m) {
			int dx = abs(p[i].first - c[j].first);
			int dy = abs(p[i].second - c[j].second);
			if (dx + dy < mn) {
				mn = dx + dy;
				ans = j;
			}
		}
		cout << ans + 1 << endl;
	}
	return 0;
}