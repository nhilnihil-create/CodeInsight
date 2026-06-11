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
constexpr ll MOD_LL = ll(1e9) + 7;

int main(void) {
	ll a, b, c;
	cin >> a >> b >> c;
	
	vector<ll> L = {a, b, c};
	sort(L.begin(), L.end());
	
	if( L[2] % 2 == 0 ) cout << 0 << endl;
	else cout << L[0] * L[1] << endl;

	return 0;
}
