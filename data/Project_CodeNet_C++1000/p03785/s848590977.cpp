#include <iostream>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <utility>
#include <cctype>

using namespace std;

using ll = long long;
using P = pair<double, double>;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define mkp(a, b) make_pair(a, b)




int main() {
	int n, c, k;
	cin >> n >> c >> k;

	vector<int> t(n);

	rep(i ,n) {
		cin >> t[i];
	}
	sort(t.begin(), t.end());

	int nt = -1;
	int cc = 0;
	int ans = 0;

	for(int i = 0; i < n; i++) {
		//cout << "i:" << i << " cc:" << cc << " t:" << t[i] << " nt:" << nt << " ans:" << ans << endl; 
		cc++; 
		if (cc >= c) {
			cc = 0;
			ans++;
			nt = -1;
			continue;
		}

		if (nt == -1) {
			nt = t[i] + k;
		}  

		if (i < n - 1 && t[i + 1] > nt) {
			cc = 0;
			ans++;
			nt = -1;
		}
	}
	if (cc > 0) {
		ans++;
	}
	cout << ans << endl;

	return 0;
}
