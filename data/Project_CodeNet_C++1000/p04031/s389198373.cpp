#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <numeric>
#include <set>
#include <queue>
#include <list>
using namespace std;
typedef long long ll;

void solve() {
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)cin >> v[i];
	int sum = accumulate(v.begin(), v.end(), 0) / n;
	int ans1 = 0, ans2 = 0;
	for (int i : v)ans1 += (sum - i) * (sum - i);
	for (int i : v)ans2 += (sum + 1 - i) * (sum + 1 - i);
	cout << min(ans1, ans2) << endl;


}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// int t; cin >> t;
	// while (t--)
	solve();

}