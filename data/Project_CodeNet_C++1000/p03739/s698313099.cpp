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
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	ll res1 = 0;
	ll sum = 0;
	rep(i, n) {
		sum += a[i];
		if (i % 2 == 0) {
			if (sum <= 0) {
				res1 += 1 - sum;
				sum = 1;
			}
		}
		else {
			if (sum >= 0) {
				res1 += sum + 1;
				sum = -1;
			}
		}
	}
	ll res2 = 0;
	sum = 0;
	rep(i, n) {
		sum += a[i];
		if (i % 2 == 1) {
			if (sum <= 0) {
				res2 += 1 - sum;
				sum = 1;
			}
		}
		else {
			if (sum >= 0) {
				res2 += sum + 1;
				sum = -1;
			}
		}
	}
	ll ans = min(res1, res2);
	cout << ans << endl;
	return 0;
}