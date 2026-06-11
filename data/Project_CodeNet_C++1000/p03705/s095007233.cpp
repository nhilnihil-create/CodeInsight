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
	ll n, a, b;
	cin >> n >> a >> b;
	
	if( a > b ) {
		cout << 0 << endl;
	} else {
		if( n == 1 ) {
			if( a != b ) cout << 0 << endl;
			else cout << 1 << endl;
		}
		
		else cout << (b - a) * (n - 2LL) + 1LL << endl;
	}
	
	return 0;
}
