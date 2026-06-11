#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<ll, int> P;
typedef tuple<int, int, int> T;
constexpr auto INF = INT_MAX >> 1;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

int main() {

	int n;
	cin >> n;
	vi a(n);
	rep(i, n)cin >> a[i];
	sort(all(a));
	V<ll> sum(n + 1);
	rep(i, n)sum[i + 1] = sum[i] + a[i];

	int ans = 0;

	rep(i, n) {

		ll d = a[i];
		bool ok = false;

		while (true) {
			int k = upper_bound(all(a), 2 * d) - a.begin();
			if (k == n) { ok = true;break; }
			if (d == sum[k])break;
			d = sum[k];
		}
		if (ok) {
			ans = n - i;
			break;
		}

	}
	
	cout << ans << endl;

}