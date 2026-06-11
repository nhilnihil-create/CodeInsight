#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int, int, int> T;
constexpr auto INF = INT_MAX >> 1;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

ll com(int n, int r) {

	ll re = 1;

	rep(i, r) {
		re *= n - r + 1 + i;
		re /= i + 1;
	}

	return re;

}

int main() {

	int n, a, b;
	cin >> n >> a >> b;
	V<ll> v(n);
	rep(i, n)cin >> v[i];
	sort(all(v), greater<ll>());
	ll sum = 0;
	rep(i, a)sum += v[i];

	cout << fixed << setprecision(8);
	cout << (double)sum / a << endl;

	ll ans = 0;

	if (v[0] == v[a - 1]) {
		reverse(all(v));
		int k = upper_bound(all(v), v[n - 1]) - lower_bound(all(v), v[n - 1]);
		for (int i = a;i <= min(k, b);i++)ans += com(k, i);
		cout << ans << endl;
	}
	else {
		reverse(all(v));
		int k = upper_bound(all(v), v[n - a]) - lower_bound(all(v), v[n - a]);
		int l = upper_bound(all(v), v[n - a]) - v.begin();
		l -= n - a;
		ans = com(k, l);
		cout << ans << endl;
	}

}