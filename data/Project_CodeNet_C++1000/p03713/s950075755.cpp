#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
using P = pair<ll, ll>;
using V = vector<ll>;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep1(i, n) for(ll i=1;i<=(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
#define ALL(obj) (obj).begin(), (obj).end()
#define RALL(obj) (obj).rbegin(), (obj).rend()
#define MOD 1000000007
#define INF 1000000000

void solve_abc_c() {
	ll n, m, x, h, w;
	ll ans = 0;
	//float ans = 0;
	cin >> h >> w;


	ll r1, r2, r3;
	if (h % 3 == 0 || w % 3 == 0) {
		ans = 0;
	}
	else {
		ans = INF;

		ans = min(ans, abs((h / 3 + 1) * w - (h / 3) * w));
		ans = min(ans, abs((w / 3 + 1) * h - (w / 3) * h));


		if (h % 2 == 0) {
			rep2(i, 1, w) {
				ans = min(ans, abs(h * i - h / 2 * (w - i)));
			}
		}
		else {
			rep2(i, 1, w) {
				r1 = h * i;
				r2 = h / 2 * (w - i);
				r3 = (h / 2 + 1) * (w - i);
				if (r1 >= r2 && r2 >= r3) {
					ans = min(ans, abs(r1 - r2));
				}
				else if (r3 >= r2 && r2 >= r1) {
					ans = min(ans, abs(r3 - r1));
				}
				else if (r3 >= r1 && r1 >= r2) {
					ans = min(ans, abs(r3 - r2));
				}
			}
		}

		if (w % 2 == 0) {
			rep2(i, 1, h) {
				ans = min(ans, abs(w * i - w / 2 * (h - i)));
			}
		}
		else {
			rep2(i, 1, h) {
				r1 = w * i;
				r2 = w / 2 * (h - i);
				r3 = (w / 2 + 1) * (h - i);
				if (r1 >= r3 && r3 >= r2) {
					ans = min(ans, abs(r1 - r2));
				}
				else if (r3 >= r2 && r2 >= r1) {
					ans = min(ans, abs(r3 - r1));
				}
				else if (r3 >= r1 && r1 >= r2) {
					ans = min(ans, abs(r3 - r2));
				}
			}
		}
	}

	cout << ans << "\n";
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	//cout << fixed;
	//cout << setprecision(7);

	solve_abc_c();

	return 0;
}
