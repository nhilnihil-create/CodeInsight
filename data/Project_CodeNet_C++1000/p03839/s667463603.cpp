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
#define rep_r(i,s,n)for(int i = n-1;i>=s;i--)
#define rep_re(i,s,n)for(int i = n;i>=s;i--)
using namespace std;
typedef long long ll;
static const ll MOD = 1e9 + 7;
static const ll INF = 1e25;
static const ll MAX_M = 100001;

ll a[100001] = {};
ll s[100001] = {};
ll b[100001] = {};
ll w[100001] = {};

int main() {
	ll n, k; cin >> n >> k;
	repe(i, 1, n) {
		cin >> a[i];
		s[i] += s[i - 1] + a[i];

		if (a[i] > 0) {
			b[i] += b[i - 1] + a[i];
			w[i] += w[i - 1];
		}
		else {
			w[i] += w[i - 1] + a[i];
			b[i] += b[i - 1];
		}
	}
	ll ans = 0;
	repe(i, 1, n - k + 1) {
		ll minW = b[i - 1] - b[0]
			+ b[n] - b[i + k - 1];
		ll minB = s[i + k - 1] - s[i - 1]
			+ minW;

		ans = max(max(minW, minB), ans);
	}
	cout << ans << endl;

	return 0;
}
