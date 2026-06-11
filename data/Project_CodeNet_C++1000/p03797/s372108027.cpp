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
#define rep(i, n) for (ll i = 0; i < n; i++)
const long long mod = 1000000007;
typedef long long int ll;
typedef pair<int, int> P;
const vector<int> di = { -1, 0, 1, 0 };
const vector<int> dj = { 0, 1, 0, -1 };


int main() {

	ll n, m;
	cin >> n >> m;
	ll ans = 0;
	if (n * 2 > m) {
		if (m % 2 == 0) {
			ans = m / 2;
			cout << ans << endl;
		}
		else {
			ans = (m - 1) / 2;
			cout << ans << endl;
		}
	}
	else if (n * 2 == m) {
		ans = n;
		cout << ans << endl;
	}
	else if (n * 2 < m) {
		ans = n + (m - n * 2) / 4;
		cout << ans << endl;
	}
	
	return 0;
}