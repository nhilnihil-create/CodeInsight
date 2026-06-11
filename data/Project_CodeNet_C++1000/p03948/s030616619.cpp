#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<map>
#include<vector>
#include<math.h>
#include<stdio.h>
#include<stack>
#include<queue>
#include<tuple>
#include<cassert>
#include<set>
#include<functional>
#define int long long
#define mod(int)(1000000007)
using namespace std;
const int INF = 1000000000000;
int test[345678], mi[345678], cnt[345678];
signed main() {
	int n, m, sum = 0, ans = 0; cin >> n >> m;
	for (int h = 0; h < n; h++) {
		cin >> test[h];
	}
	mi[0] = test[0];
	for (int h = 1; h < n; h++) {
		mi[h] = min(mi[h - 1], test[h]);
	}
	for (int h = 0; h < n; h++) {
		cnt[h] = test[h] - mi[h]; sum = max(sum, cnt[h]);
	}
	for (int h = 0; h < n; h++) {
		if (cnt[h] == sum)ans++;
	}
	cout << ans << endl;
}