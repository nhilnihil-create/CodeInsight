#include <algorithm>
#include <cfloat>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
#define int long long
#define ll long long
#define eps LDBL_EPSILON
#define mod 1000000007
#define int long long
#define double long double
#define INF LLONG_MAX/1000
#define P pair<int,int>
#define prique priority_queue
using namespace std;
int n, k, a[200010];

int m, node[1000010], lazy[1000010];
bool clearf[1000010];
void init(int n_) {
	m = 1;
	while (m < n_)m *= 2;
}
void eval(int k, int l, int r) {
	if (lazy[k] != 0) {
		node[k] += lazy[k];
		if (r - l > 1) {
			lazy[2 * k + 1] += lazy[k] / 2;
			lazy[2 * k + 2] += lazy[k] / 2;
		}
		lazy[k] = 0;
	}
}

void add(int a, int b, int x, int k = 0, int l = 0, int r = -1) {
	if (r < 0)r = m;
	eval(k, l, r);
	if (b <= l || r <= a)return;
	if (a <= l && r <= b) {
		lazy[k] += (r - l) * x;
		eval(k, l, r);
	}
	else {
		add(a, b, x, 2 * k + 1, l, (l + r) / 2);
		add(a, b, x, 2 * k + 2, (l + r) / 2, r);
		node[k] = node[2 * k + 1] + node[2 * k + 2];
	}
}

int getsum(int a, int b, int k = 0, int l = 0, int r = -1) {
	if (r < 0)r = m;
	eval(k, l, r);
	if (b <= l || r <= a)return 0;
	if (a <= l && r <= b)return node[k];
	int vl = getsum(a, b, 2 * k + 1, l, (l + r) / 2);
	int vr = getsum(a, b, 2 * k + 2, (l + r) / 2, r);
	return vl + vr;
}

signed main() {
	cin >> n >> k;
	map<int, int> mp;
	mp[0] = 0;
	REP(i, n) {
		cin >> a[i];
		a[i] -= k;
		if (i)a[i] += a[i - 1];
		mp[a[i]] = 0;
	}
	int cnt = 0;
	for (auto ite = mp.begin(); ite != mp.end(); ite++) {
		(*ite).second = cnt;
		cnt++;
	}
	rep(i, n + 1)a[i] = mp[a[i]];
	int ans = 0;
	init(n + 10);
	rep(i, n + 1) {
		ans += getsum(0, a[i] + 1);
		add(a[i], a[i] + 1, 1);
	}
	cout << ans << endl;
	return 0;
}