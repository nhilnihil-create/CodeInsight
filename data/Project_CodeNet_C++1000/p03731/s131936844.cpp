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
#include <cstdint>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
const long long mod = 1000000007;
typedef long long int ll;
typedef pair<ll, ll> P;
const vector<int> di = { -1, 0, 1, 0 };
const vector<int> dj = { 0, 1, 0, -1 };



int main() {

	int n;
	cin >> n;
	ll T;
	cin >> T;
	vector<ll> t(n);
	rep(i, n) cin >> t.at(i);

	ll ans = 0;
	rep(i, n - 1) {
		int diff = t.at(i + 1) - t.at(i);

		if (diff <= T) {
			ans += diff;
			continue;
		}
		else{
			ans += T;
		}
	}
	ans += T;
	cout << ans << endl;


	return 0;
}

