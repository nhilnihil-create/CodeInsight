#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define maxs(a, b) a = max(a, b)
#define mins(a, b) a = min(a, b)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll linf = (1ll << 61);
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	int ans = inf;
	auto keta = [&](ll a) {
		int res = 0;
		while (a) res++, a /= 10;
		return res;
	};
	for (ll i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			mins(ans, max(keta(i), keta(n / i)));
		}
	}
	cout << ans << endl;
	return 0;
}
