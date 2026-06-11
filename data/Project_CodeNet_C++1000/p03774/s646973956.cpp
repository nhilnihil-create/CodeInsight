#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
	int n, m;
	ll a, b, c, d;
	cin >> n >> m;
	vector<pair<ll,ll>>stu, chk;
	rep(i, n) { cin >> a >> b; stu.push_back(make_pair(a, b)); }
	rep(i, m) { cin >> c >> d; chk.push_back(make_pair(c, d)); }
	ll mdist = INF;
	int cp = 0;
	ll sx, cx, sy, cy;
	rep(i, n) {
		mdist = INF;
		sx = stu[i].first;
		sy = stu[i].second;
		rep(j, m) {
			cx = chk[j].first;
			cy = chk[j].second;
			if (mdist > (abs(sx - cx) + abs(sy - cy))) {
				mdist = (abs(sx - cx) + abs(sy - cy));
				cp = j;
			}
		}
		cout << cp + 1 << endl;
	}
	return 0;
}
