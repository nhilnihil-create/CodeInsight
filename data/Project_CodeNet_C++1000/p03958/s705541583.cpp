#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;
int a[100]; 
int main() {
	int k, t;
	cin >> k >> t;
	int all = 0;
	rep(i,t) {
		cin >> a[i];
		all += a[i];
	}
	sort(a,a+t);
	
	int ans = k;
	int l = 0, r = all;
	rep(i,t) {
		l += a[i];
		r -= a[i];
		ans = min(ans, abs(l-r));
	}
	
	if (ans == 0) cout << 0 << endl;
	else cout << ans-1 << endl;

	return 0;
}