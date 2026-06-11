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
typedef pair<int, int> P;
const vector<int> di = { -1, 0, 1, 0 };
const vector<int> dj = { 0, 1, 0, -1 };


int main() {

	ll x;
	cin >> x;

	ll ans = 0;

	if (x % 11 > 6) {
		ans = (x / 11) * 2 + 2;
	}
	else if (x % 11 > 0) {
		ans = (x / 11) * 2 + 1;
	}
	else {
		ans = (x / 11) * 2;
	}

	cout << ans << endl;
	
	return 0;
}