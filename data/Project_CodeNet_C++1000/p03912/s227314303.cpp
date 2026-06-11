#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
constexpr auto INF = INT_MAX >> 1;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

int main() {

	int n, m;
	cin >> n >> m;
	vi x(n);
	rep(i, n)cin >> x[i];
	sort(all(x));

	vi modm(m, 0);
	vi same(m, 0);
	int k = 1;

	rep(i, n) {
		modm[x[i] % m]++;
		if (i == 0)continue;
		if (x[i - 1] == x[i])k++;
		else {
			same[x[i - 1] % m] += k / 2;
			k = 1;
		}
	}
	same[x[n - 1] % m] += k / 2;

	int ans = 0;

	rep(i, m) {
		if (i == 0 || i * 2 == m) { ans += modm[i] / 2;continue; }
		if (i * 2 > m)continue;

		ans += min(modm[i], modm[m - i]);
		if (modm[i] >= modm[m - i])ans += min(same[i], (modm[i] - modm[m - i]) / 2);
		else ans += min(same[m - i], (modm[m - i] - modm[i]) / 2);

	}

	cout << ans << endl;

}