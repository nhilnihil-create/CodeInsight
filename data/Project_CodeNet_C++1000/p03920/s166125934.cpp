#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int sum = 0, t = 1;
	vector<int> ans;
	while (sum < n) {
		ans.push_back(t);
		sum += t;
		t++;
	}
	for (auto &p : ans) {
		if(p == sum - n) continue;
		cout << p << endl;
	}
	return 0;
}