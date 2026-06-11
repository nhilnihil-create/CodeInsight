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
const ll linf = 1001002003004005006ll;
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	ll tot = 0;
	ll res1 = 0;
	{//i = 0 -> +
		rep(i, n) {
			if (i % 2 == 0) {
				if (tot + a[i] > 0) tot += a[i];
				else {
					res1 += 1 - tot - a[i];
					tot = 1;
				}
			}
			else {
				if (tot + a[i] < 0) tot += a[i];
				else {
					res1 += 1 + tot + a[i];
					tot = -1;
				}
			}
		}
	}
	tot = 0;
	ll res2 = 0;
	{//gyaku
		rep(i, n) {
			if (i % 2 != 0) {
				if (tot + a[i] > 0) tot += a[i];
				else {
					res2 += 1 - tot - a[i];
					tot = 1;
				}
			}
			else {
				if (tot + a[i] < 0) tot += a[i];
				else {
					res2 += 1 + tot + a[i];
					tot = -1;
				}
			}
		}
	}
	ll ans = min(res1, res2);
	cout << ans << endl;
	return 0;
}