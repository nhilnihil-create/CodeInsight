#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;
int x[100010], w[100010], ans[100010];
int main() {
	int n,l,t;
	cin >> n >> l >> t;

	rep(i,n) {
		cin >> x[i] >> w[i];
		if (w[i] == 1) {
			ans[i] = (x[i] + t) % l; 
		} else {
			ans[i] = ((x[i]-t)%l+l) % l;
		}
	}
	int p = 0;
	rep(i,n) {
		if (w[i] == 1) p = (p+(x[i]+t)/l)%n;
		else p = ((p-(l-x[i]+t-1)/l)%n+n)%n;

	}
	sort(ans,ans+n);
	rep(i,n) {
		cout << ans[(i+p)%n] << endl;
	}
	return 0;
}