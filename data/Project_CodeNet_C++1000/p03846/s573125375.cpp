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
	vector<int> a(n);
	rep(i, n) cin >> a.at(i);
	ll num = 1;
	rep(i, n / 2) {
		num = num * 2 % mod;
	}
	sort(a.begin(), a.end());

	if (n % 2 == 0) {
		bool cheak = true;
		rep(i, n / 2) {
			if (a.at(i * 2) != a.at(i * 2 + 1)) {
				cheak = false;
				break;
			}
		}
		if (cheak == false) {
			cout << 0 << endl;
		}
		else {
			ll ans = num;
			cout << ans << endl;
		}
	}
	else {
		bool cheak = true;
		if (a.at(0) != 0) {
			cheak = false;
		}
		rep(i, n / 2) {
			if (a.at(i * 2 + 1) != a.at(i * 2 + 2)) {
				cheak = false;
				break;
			}
		}
		if (cheak == false) {
			cout << 0 << endl;
		}
		else {
			ll ans = num;
			cout << ans << endl;
		}
	}

	return 0;
}