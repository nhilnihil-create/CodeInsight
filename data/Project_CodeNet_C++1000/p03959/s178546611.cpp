#include <algorithm>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
#define eps LDBL_EPSILON
#define moder 1000000007
#define int long long
#define ll long long
#define double long double
#define INF LLONG_MAX/3
#define P pair<int,int>
#define prique priority_queue<int,vector<int>,greater<int>>
using namespace std;
int n, a[100010], t[100010];
int memo[100010];
int height[100010];
bool d[100010];
signed main() {
	cin >> n;
	fill(memo, memo + n, INF);
	rep(i, n) {
		cin >> a[i];
		if (!i || a[i - 1] != a[i]) {
			d[i] = true;
			height[i] = a[i];
		}
		else memo[i] = min(memo[i], a[i]);
	}
	rep(i, n)cin >> t[i];
	reverse(t, t + n);
	rep(i, n) {
		if (!i || t[i - 1] != t[i]) {
			d[n - i - 1] = true;
			height[n - i - 1] = t[i];
		}
		else memo[n - i - 1] = min(memo[n - i - 1], t[i]);
	}
	rep(i, n) {
		if (!d[i])height[i] = 1;
	}
	if (height[0] != a[0]) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 1; i < n; i++) {
		if (a[i] != max(a[i - 1], height[i])) {
			cout << 0 << endl;
			return 0;
		}
	}
	rep(i, n - 1) {
		if (t[n - i - 1] != max(t[n - i - 2], height[i])) {
			cout << 0 << endl;
			return 0;
		}
	}
	if (height[n - 1] != t[0]) {
		cout << 0 << endl;
		return 0;
	}
	int ans = 1;
	rep(i, n) {
		if (!d[i])ans *= memo[i];
		ans %= moder;
	}
	cout << ans << endl;
}