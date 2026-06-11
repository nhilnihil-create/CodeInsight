#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using i64 = int64_t;
#define rep(i, j, n) for(int i = (j); i < (n); ++i)
int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);

	int n, a; cin >> n;
	vector<pair<int, int>> p;
	rep(i, 0, n) {
		cin >> a;
		p.emplace_back(a, i);
	}
	sort(p.begin(), p.end());
	

	int ans = 0;
	rep(i, 0, n) 
		ans += (p[i].second + i) & 1;
	
	cout << ans / 2 << endl;

	return 0;
}