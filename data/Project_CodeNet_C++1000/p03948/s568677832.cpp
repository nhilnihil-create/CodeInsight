#include <bits/stdc++.h>
#define int long long
#define range(i, a, b) for(auto i = a; i < b; i++)
#define rep(i, a) range(i, 0, a)
#define all(a) (a).begin(),(a).end()
using namespace std;
const int INF = sizeof(int) == sizeof(long long) ? 1000000000000000000LL : 1000000000;
const int MOD = 1000000007;
const long double EPS = 1e-8;
using vi = vector <int>;
using vvi = vector <vi>;

signed main() {
	int n, t;
	cin >> n >> t;
	int in, mini = INF, macs = -INF, ans = 1;
	rep (i, n) {
		cin >> in;
		if (mini <= in) {
			if (macs < in - mini) {
				macs = in - mini;
				ans = 1;
			} else if (macs == in - mini) {
				ans++;
			}
		} else {
			mini = in;
		}
	}
	cout << ans << endl;
	return 0;
}