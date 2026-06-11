#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	int n;
	cin >> n;
	vector<int> ans;
	rep(i, n) {
		int a;
		cin >> a;
		if (i % 2 == 1) ans.insert(ans.begin(), a);
		else ans.push_back(a);
	}
	if (n % 2 == 1) reverse(ans.begin(), ans.end());
	rep(i, n) cout << ans[i] << " ";
	cout << endl; 
	return 0;
}