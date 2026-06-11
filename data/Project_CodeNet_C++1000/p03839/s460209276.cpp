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
#define INF LLONG_MAX/10000
#define P pair<int,int>
#define prique priority_queue
using namespace std;
int n, k, a[100010], b[100010], c[100010];
signed main() {
	cin >> n >> k;
	rep(i, n) {
		cin >> a[i];
		b[i] = a[i];
		if (a[i] > 0)c[i] = a[i];
		if (i) {
			b[i] += b[i - 1];
			c[i] += c[i - 1];
		}
	}
	int ans = 0;
	rep(i, n - k + 1) {
		int cnt = 0;
		if (i)cnt += b[i + k - 1] - b[i - 1];
		else cnt += b[i + k - 1];
		cnt = max(cnt, (ll)0);
		if(i)cnt += c[i - 1];
		cnt += c[n - 1] - c[i + k - 1];
		ans = max(ans, cnt);
	}
	cout << ans << endl;
	return 0;
}