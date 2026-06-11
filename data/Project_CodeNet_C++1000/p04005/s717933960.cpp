#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <utility>
#include <numeric>
#include <queue>
#include <stack>

using ll = long long;
using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr ll MOD_LL = ll(1e9 + 7);

int main(void) {
	ll a, b, c;
	cin >> a >> b >> c;
	
	vector<ll> x = {a, b, c};
	sort(x.begin(), x.end());
	
	if( x[2] % 2 == 0 ) {
		cout << 0 << endl;
	} else {
		cout << (x[0] * x[1]) * ( ( (x[2] + 1) / 2) - (x[2] / 2) ) << endl;
	}
	
	return 0;
}
