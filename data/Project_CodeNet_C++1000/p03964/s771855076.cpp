#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <functional>
#include <iomanip>
#include <bitset>
#include <numeric>
#include <queue>
#include <map>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
const long long mod = 1000000007;
typedef long long ll;
typedef pair<int, int> P;
const vector<int> di = {-1, 0, 1, 0};
const vector<int> dj = { 0, 1, 0, -1 };

int main() {

	int n;
	cin >> n;
	vector<ll> t(n);
	vector<ll> a(n);
	rep(i, n) cin >> t.at(i) >> a.at(i);

	ll ans = 0;
	rep(i, n) {
		if (i == 0) {
			ans = t.at(0) + a.at(0);
			continue;
		}
		if (t.at(i) >= t.at(i - 1) && a.at(i) >= a.at(i - 1)) {
			ans = t.at(i) + a.at(i);
			continue;
		}
		else {
			ll num = max(t.at(i - 1) / t.at(i), a.at(i - 1) / a.at(i));
			t.at(i) = t.at(i) * num;
			a.at(i) = a.at(i) * num;
			if (t.at(i) >= t.at(i - 1) && a.at(i) >= a.at(i - 1)) {
				ans = t.at(i) + a.at(i);
			}
			else {
				t.at(i) += t.at(i) / num;
				a.at(i) += a.at(i) / num;
				ans = t.at(i) + a.at(i);
			}
		}
	}
	cout << ans << endl;
	
	return 0;
}