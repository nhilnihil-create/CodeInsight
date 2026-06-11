#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<vector<int>> Graph;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int main() {
	int A, B, C, D, E, F; cin >> A >> B >> C >> D >> E >> F;
	ll M_mother = inf, M_child = 0;
	int mt_ans = 0, ms_ans = 0;
	for(int i = 0; i <= 30; i++) {
		for(int j = 0; j <= 30; j++) {
			if(i == 0 && j == 0) continue;
			int mw = 100 * (i * A + j * B);
			if(mw > F) break;
			for(int u = 0; u <= (mw * E / 100); u++) {
				for(int v = 0; v <= (mw * E / 100); v++) {
					int ms = u * C + v * D;
					if(mw + ms > F) break;
					if(ms > mw * E / 100) break;
					ll moist_mother = mw + ms, moist_child = 100 * ms;
					if(moist_child * M_mother >= M_child * moist_mother) {
						M_mother = moist_mother; M_child = moist_child;
						mt_ans = mw + ms;
						ms_ans = ms;
					}
				}
			}
		}
	}
	cout << mt_ans << " " << ms_ans << endl;
}