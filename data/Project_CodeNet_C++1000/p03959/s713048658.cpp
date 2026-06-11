#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <vector>
#include <math.h>
#include <bitset>
#include <cmath>
#include <set>

#define rep(i,s,n)for(int i = s;i<n;i++)
#define repe(i,s,n)for(int i = s;i<=n;i++)
#define rep_r(i,s,n)for(int i = n;i>s;i--)
#define rep_re(i,s,n)for(int i = n;i>=s;i--)
using namespace std;
typedef long long ll;
static const ll MOD = 1e9 + 7;
static const ll INF = 1e25;
static const ll MAX_N = 100001;

ll t[100001];
ll a[100001];
ll maxV[100001];
ll minV[100001];
bool ok[100001];

int  main() {
	ll n; cin >> n;

	repe(i, 1, n) cin >> t[i];
	repe(i, 1, n) cin >> a[i];

	if (t[n] != a[1]) {
		cout << 0 << endl;
		return 0;
	}
	//t
	repe(i, 1, n) {
		ll T = t[i];
		if (t[i - 1] < t[i]) {
			maxV[i] = T;
			ok[i] = true;
		}
		else {
			maxV[i] = T;
		}
	}

	//a
	rep_r(i, 0, n) {
		ll A = a[i];

		if (a[i] > a[i + 1]) {
			if (ok[i]) {
				if (A != maxV[i]) {
					cout << 0 << endl;
					return 0;
				}
				else {
					continue;
				}
			}
			ok[i] = true;
			maxV[i] = A;
		}
		else {
			if (ok[i]) {
				if (maxV[i] > A) {
					cout << 0 << endl;
					return 0;
				}
				else {
					continue;
				}
			}
			maxV[i] = min(A, maxV[i]);
		}
	}

	ll ans = 1;
	repe(i, 1, n) {
		if (!ok[i]) {
		ans = ans * maxV[i] % MOD;

		}
	}
	cout << ans << endl;
	return 0;
}