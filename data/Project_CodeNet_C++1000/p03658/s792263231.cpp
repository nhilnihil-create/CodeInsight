#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n, k; cin >> n >> k;
	vector<int>l(n); for (auto&& x : l)cin >> x;
	sort(l.rbegin(), l.rend());
	int ans = 0;
	for (int i = 0; i < k; i++) {
		ans += l[i];
	}
	cout << ans << endl;

	return 0;
}