#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <list>
#include <iomanip>
#include <queue>
#include <cmath>
#include <numeric>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)

using namespace std;
using ll = long long;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {

	ll AMAX = 100000;
	vector<ll> s(AMAX + 1, 0);

	ll N, K;
	cin >> N >> K;
	
	ll a, b;

	rep(i, N) {
		cin >> a >> b;
		s[a] += b;
	}
	
	ll tmp = 0, ans;

	rep(i, AMAX + 1) {
		tmp += s[i];
		if (tmp >= K) {
			ans = i;
			break;
		}
	}

	cout << ans;

	return 0;
}
