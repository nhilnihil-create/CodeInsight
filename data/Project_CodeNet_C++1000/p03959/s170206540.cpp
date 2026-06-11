#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<ll, ll> P;
constexpr auto INF = INT_MAX >> 1;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

int main() {

	int n;
	cin >> n;
	vi t(n), a(n);
	rep(i, n)cin >> t[i];
	rep(i, n)cin >> a[i];

	ll ans = 1;

	if (t[n - 1] != a[0])ans *= 0;
	if (n >= 2) {
		if (a[0] > a[1] && t[0] != a[0])ans *= 0;
		if (t[n - 2] < t[n - 1] && t[n - 1] != a[n - 1])ans *= 0;
	}
	rep(i, n - 2) {
		if (t[i] < t[i + 1] && t[i + 1] > a[i + 1])ans *= 0;
		if (a[i + 1] > a[i + 2] && t[i + 1] < a[i + 1])ans *= 0;
		if (t[i] < t[i + 1] || a[i + 1] > a[i + 2])continue;
		ans *= min(t[i + 1], a[i + 1]);
		ans %= MOD;
	}

	cout << ans << endl;

}