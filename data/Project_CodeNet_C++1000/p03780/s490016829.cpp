#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define _USE_MATH_DEFINES
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <math.h>
#include <complex>
#include <cassert>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
typedef complex<double> com;
const int mod = 1e9 + 7;
const int MOD = 998244353;
const int INF = 2e9;



int main() {
	int n, k; cin >> n >> k;
	vector<int> a(n);
	rep(i, 0, n) cin >> a[i];
	sort(a.begin(), a.end(),greater<int>());
	ll sum; int ans = 0;
	rep(i, 0, n) {
		sum = 0;
		rep(j, i, n) {
			sum += a[j];
			if (sum >= k) {
				ans = max(ans, j + 1);
				sum -= a[j];
			}
		}
	}
	ans = n - ans;
	printf("%d", ans);
	return 0;
}
