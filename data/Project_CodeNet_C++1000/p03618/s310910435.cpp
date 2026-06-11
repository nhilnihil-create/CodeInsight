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

using namespace std;

using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define mkp(a, b) make_pair(a, b)
const int inf = 1e+9;



int main() {
	string s;
	cin >> s;

	vector<ll> cs(26,0);

	int n = s.size();
	for(char c : s) {
		cs[c - 'a']++;
	}

	ll ans = 0;

	bool plus1 = false;

	for (int i = 0; i < 26; i++) {
		if (cs[i] >= 2) {
			plus1 = true;
		}
		ans += (n - cs[i]) * cs[i];
	}
	ans /= 2;

	ans++;
	cout << ans << endl;
	

	return 0;
}
