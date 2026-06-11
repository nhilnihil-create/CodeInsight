#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cfloat>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <list>
#include <map>
#include <math.h>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <string.h>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
#define int long long
#define ll long long
#define eps LDBL_EPSILON
#define mod (ll)1000000007
#define INF LLONG_MAX/10
#define P pair<int,int>
#define prique priority_queue
using namespace std;
int n, a;
vector<int> vec[100010];
int depth[100010];
void dfs(int node, int d) {
	depth[node] = d;
	for (int i : vec[node]) {
		dfs(i, d + 1);
	}
}
int func(int node) {
	if (vec[node].empty())return 0;
	int ma = 0;
	vector<int> memo;
	for (int i : vec[node]) {
		int f = func(i);
		ma = max(ma, f);
		memo.push_back(f);
	}
	sort(memo.begin(), memo.end());
	int q = 0, b = 0;
	rep(i, memo.size()) {
		if (i == 0) {
			b = memo[i];
			q++;
		}
		else if (memo[i] == b)q++;
		else {
			q -= memo[i] - b;
			q = max(q, (ll)0);
			q++;
			b = memo[i];
		}
	}
	return q + ma;
}
signed main() {
	cin >> n;
	for (int i = 2; i <= n; i++) {
		cin >> a;
		vec[a].push_back(i);
	}
	dfs(1, 0);
	cout << func(1) << endl;
	return 0;
}