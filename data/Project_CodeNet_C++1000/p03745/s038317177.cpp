#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define get(vv, times) for(int ii = 0; ii < times; ++ii) {int jj; cin >> jj; (vv).pb(jj);}
#define all(vv) (vv).begin(), (vv).end()

int n, state, pre, ans;
vector <int> a;

int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	get(a, n);
	// 0 -> same, 1 -> increasing, 2 -> decreasing
	state = -1, pre = 0, ans = 1;
	for(int i = 0; i < n; ++i) {
		if (state == -1) {
			state = 0;
		}
		else if (state == 0) {
			if (a[i] > pre) state = 1;
			else if (a[i] < pre) state = 2;
			else if (a[i] == pre) state = 0;
		}
		else if (state == 1) {
			if (a[i] < pre) {
				++ans;
				state = 0;
			}
		}
		else if (state == 2) {
			if (a[i] > pre) {
				++ans;
				state = 0;
			}
		}
		pre = a[i];
	}
	cout << ans;
}