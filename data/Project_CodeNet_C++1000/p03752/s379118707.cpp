#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ALL(a) (a).begin(), (a).end()
#define rALL(a) (a).rbegin(), (a).rend()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int iINF = 1001001001;
const long long llINF = 1LL << 60;
int main()
{
	// Square869120Contest #4 B, 
	int n, k; cin >> n >> k;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	ll ans = llINF;
	rep(i, 1 << n) {
		int c = 0;
		rep(j, n) c += i >> j & 1;
		if (c != k) continue;
		ll tmpMax = -1;
		ll tmpAns = 0;
		rep(j, n) {
			if (i >> j & 1) {
				tmpAns += max(0ll, tmpMax - a[j] + 1);
				tmpMax = max(tmpMax + 1, a[j]);
			}
			else {
				tmpMax = max(tmpMax, a[j]);
			}
		}
		ans = min(ans, tmpAns);
	}
	cout << ans << endl;

	return 0;
}