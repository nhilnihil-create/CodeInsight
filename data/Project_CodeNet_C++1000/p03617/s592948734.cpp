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
#include <iomanip>

using ll = long long;
using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr ll MOD_LL = ll(1e9 + 7);

int main(void) {
	ll q, h, s, d, n;
	cin >> q >> h >> s >> d >> n;
	
	ll bottom = min( {4LL * q, 2LL * h, s} );
	ll ans = min(d * (n / 2LL) + (n % 2LL) * bottom, n * bottom);
	
	cout << ans << endl;
	
	return 0;
}
