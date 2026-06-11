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
vector<int> vec[100010], ans;
bool used[100010];
void dfs(int s) {
	used[s] = true;
	ans.push_back(s);
	for (int i : vec[s]) {
		if (!used[i]){
			dfs(i);
			return;
		}
	}
}
signed main() {
	int n, m, a, b;
	cin >> n >> m;
	rep(i, m) {
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	dfs(1);
	reverse(ans.begin(), ans.end());
	for (int i : vec[1]) {
		if (!used[i]) {
			dfs(i);
			break;
		}
	}
	cout << ans.size() << endl;
	rep(i, ans.size() - 1)cout << ans[i] << " ";
	cout << ans.back() << endl;
	return 0;
}