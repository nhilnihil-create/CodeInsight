#include "bits/stdc++.h"
using namespace std;

#define int long long
#define DEBUG 0
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(a) (a).begin(),(a).end()
#define dump(o) if(DEBUG){cerr<<#o<<" "<<o<<endl;}
#define dumpc(o) if(DEBUG){cerr<<#o; for(auto &e:(o))cerr<<" "<<e;cerr<<endl;}
using pii = pair<int, int>; using vi = vector<int>;
static const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
static const int MOD = (int)(1e9 + 7);

#define MAX_X 100010

signed main() {
	int N, M; cin >> N >> M;
	int cnt[MAX_X] = {};
	//vector<vector<int>> v(5, vector<int>());
	//rep(i, 0, N) {
	//	int X; cin >> X;
	//	v[X%M].emplace_back(X);
	//	cnt[X]++;
	//}
	//rep(i, 0, 5)sort(all(v[i]));

	vector<vector<int>> v(M, vector<int>());
	rep(i, 0, N) {
		int X; cin >> X;
		v[X%M].emplace_back(X);
		cnt[X]++;
	}
	vector<int> cntd(M, 0);
	rep(i, 0, MAX_X) {
		cntd[i%M] += cnt[i] / 2;
	}

	int ans = 0;
	ans += v[0].size() / 2;
	if (M % 2 == 0)ans += v[M / 2].size() / 2;
	rep(i, 1, M / 2 + 1) {
		if (M % 2 == 0 && i == M / 2)continue;
		int c = min(cntd[i], cntd[M - i]);
		//int add = c * 2;
		//cntd[i] -= c;
		//cntd[M - i] -= c;
		//dump(c);
		int add = 0;
		int add2 = min(v[i].size(), v[M - i].size());
		int add3 = 0;
		if (add2 == v[i].size()) {
			add3 += min(
				((int)v[M - i].size() - add2) / 2,
				cntd[M - i]
			);
		}
		else {
			add3 += min(
				((int)v[i].size() - add2) / 2,
				cntd[i]
			);
		}
		dump(add);
		dump(add2);
		dump(add3);
		ans += add+add2+add3;
	}
	cout << ans << endl;
	return 0;
}