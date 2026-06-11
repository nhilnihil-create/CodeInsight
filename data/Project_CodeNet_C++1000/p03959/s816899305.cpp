#include"bits/stdc++.h"
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
const long long mod = 1000000007;
const long long inf = 1ll << 61;
typedef pair<int, int> P;
typedef pair<int,P> PP;
typedef pair<int,PP> PPP;
struct edge { int to;  int cost; };

int t[100005], a[100005], h[100005],h2[100005];

signed main() {
	int n; cin >> n;
	rep(i, n)cin >> t[i];
	rep(i, n)cin >> a[i];

	h[0] = t[0];
	h2[n - 1] = a[n - 1];
	rep(i, n - 1) {
		if (t[i] < t[i + 1]) {
			h[i+1] = t[i + 1];
		}
	}

	for (int i = n - 1; i >= 1; i--) {
		if (a[i - 1] > a[i]) {
			h2[i - 1] = a[i - 1];
		}
	}
	int ans = 1;
	rep(i, n) {
		if (!h[i] && !h2[i]) {
			ans *= min(a[i], t[i]);
			ans %= mod;
		}
		else if (h[i] && h2[i] && h[i] != h2[i])ans *= 0;
		else if (h[i] && !h2[i] && a[i] < t[i])ans *= 0;
		else if (!h[i] && h2[i] && a[i] > t[i])ans *= 0;
	}
	cout << ans << endl;
}