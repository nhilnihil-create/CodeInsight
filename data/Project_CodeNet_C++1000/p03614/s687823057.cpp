#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <numeric>
#include <stack>
#include <set>
#include <queue>
#include <list>
using namespace std;
typedef long long ll;

void solve() {
	int n, ans = 0; cin >> n;
	vector<int> v(n), temp;
	for (int &i : v)cin >> i;
	for (int i = 0; i < n; i++) {
		if (v[i] == i + 1)temp.push_back(i);
	}
	for (int i = temp.size() - 1; i >= 0; i--) {
		if (temp[i] == temp[i + 1] - 1) {
			ans++;
			temp.erase(temp.begin() + i);
			temp.erase(temp.begin() + i);
		}
	}
	cout << ans + temp.size();

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