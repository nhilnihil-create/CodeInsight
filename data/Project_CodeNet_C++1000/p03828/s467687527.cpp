#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <queue>
#include <map>
#include <stack>
#include <bitset>
#include <numeric> //lcm
#include <iomanip> //double精度 setprecision


#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = n-1; i >= 0; --i)
#define rep1(i,n) for(int i = 1; i <= (n); ++i)
#define all(vec) (vec).begin(),(vec).end()

#define debug(vec) for(auto v : vec) cout << v << " "; cout << endl;
#define debug2D(vec2D) for(auto vec : vec2D) { for (auto v : vec) cout << v << " "; cout << endl; } 

using namespace std;

typedef long long ll;

const ll INF = 1000000000; //10^10
//const ll MOD = 998244353;
const ll MOD = 1000000007;

template<class T>inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } else return false; }
template<class T>inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } else return false; }

map<ll, ll> primeFactor(ll n) {
	map<ll, ll> ret;

  for (ll i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			n /= i;
			ret[i]++;
		}
	}

	if (n != 1) ret.insert({ n,1 });

	return ret;
}

int main() {
	int n;
	cin >> n;
  
	map<ll,ll> factpf;
	rep1(i, n) {
		map<ll,ll> pf = primeFactor(i);
		for (auto pe : pf) {
			factpf[pe.first] += pe.second;
		}
	}

	ll ans = 1;
	for(auto pe : factpf) { 
	  ans *= (pe.second+1) % MOD;
		ans %= MOD;
	}

	cout << ans << endl;
}
