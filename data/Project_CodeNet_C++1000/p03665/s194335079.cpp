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
T mypow(T a, T p) {
	T ret = 1;
	while( p ) {
		if( p & 1 ) {
			ret *= a;
		}
		
		a *= a;
		p >>= 1;
	}
	
	return ret;
}

int main(void) {
	ll n, p;
	cin >> n >> p;
	
	vector<int> a(n);
	bool odd = false;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		
		if( a[i] % 2 == 1 ) odd = true;
	}
	
	if( odd ) {
		cout << mypow(2LL, n - 1LL) << endl;
	} else {
		if( p == 0 ) {
			cout << mypow(2LL, n) << endl;
		} else {
			cout << 0 << endl;
		}
	} 
	
	return 0;
}
