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

template<typename T>
T gcd(T a, T b) {
	if( a < b ) swap(a, b);
	
	T r;
	while( r = a % b ) {
		a = b;
		b = r;
	}
	
	return b;
}

template<typename T>
T lcm(T a, T b) {
	return (a / gcd(a, b)) * b;
}
int main(void) {
	int n;
	cin >> n;
	
	vector<ll> t(n);
	for(int i = 0; i < n; ++i) {
		cin >> t[i];
	}
	
	ll ans = 1LL;
	for(int i = 0; i < n; ++i) {
		ans = lcm(ans, t[i]);
	}
	
	cout << ans << endl;
	
	return 0;
}
