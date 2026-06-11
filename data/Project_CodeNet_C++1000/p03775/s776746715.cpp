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
vector<T> Divisors(T n) {
	vector<T> res;
	for(T i = 1; i * i <= n; ++i) {
		if( n % i == 0 ) {
			res.push_back(i);
			
			if( i < n / i ) res.push_back(n / i);
		}
	}
	
	sort(res.begin(), res.end());
	
	return res;
}

int f(ll a, ll b) {
	string as = to_string(a);
	string bs = to_string(b);
	
	int ad = (int)as.size();
	int bd = (int)bs.size();
	
	if( ad >= bd ) return ad;
	else return bd;
}

int main(void) {
	ll n;
	cin >> n;
	
	vector<ll> div = Divisors(n);
	
	int ans = 100;
	for(auto& v : div) {
		ans = min(ans, f(v, n / v));
	}
	
	cout << ans << endl;
	
	return 0;
}
