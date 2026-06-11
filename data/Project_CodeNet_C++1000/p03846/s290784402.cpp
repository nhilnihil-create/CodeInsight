#define _USE_NATH_DEFINES
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <complex>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <limits>
#include <climits>
#include <cfloat>
#include <functional>
#include <iterator>
#include <random>
#include <tuple>


using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
#define EPS 1e-9
const int INF = 1050000000;
const long long LINF = 1LL << 60;
const ll MOD = 1e9 + 7;
const int MINF = -1050000000;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }


int main() {
	
	ll n;
	cin >> n;
	vector<ll> a(n);

	rep(i, n) cin >> a[i];
	map<ll, ll> mp;
	bool is_exist = true;
	rep(i, n) {
		//if (n % 2 == 0 && a[i] % 2 == 0) is_exist = false;
		//if (n % 2 == 1 && a[i] % 2 == 1) is_exist = false;
		mp[a[i]]++;
	}
	for (auto x : mp) {
		ll fir = x.first, sec = x.second;
		if (n % 2 == 1) {
			if (fir == 0 && sec != 1) is_exist = false;
			else if(fir%2 != 0 && sec != 2) is_exist = false;
		}
		else {
			if (fir % 2 != 1 && sec != 2) is_exist = false;
		}
	}
	int ans = 1;
	rep(i, n/2) {
		ans *= 2;
		ans %= MOD;
	}
	if (!is_exist) cout << 0 << endl;
	else cout << ans << endl;
	return 0;
}
