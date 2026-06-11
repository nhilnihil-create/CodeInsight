#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <list>
#include <unordered_set>
#include <tuple>
#include <cmath>
#include <limits>
#include <type_traits>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <set>
#include <bitset>
#include <regex>
#include <random>
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define rep(i,n)for(ll i=0;i<n;++i)
#define exout(x) printf("%.10f\n", x)
const double pi = acos(-1.0);
const ll MOD = 1000000007;
const ll INF = 1e18;
const ll MAX_N = 201010;

//最大公約数
ll gcd(ll x, ll y) {
	return y ? gcd(y, x % y) : x;
}

ll lcm(ll x, ll y) {
	if (x == 0 || y == 0)return 0;
	return (x / gcd(x, y) * y);
}

ll dx[8] = { 1,-1,0,0,1,1,-1,-1 };
ll dy[8] = { 0,0,1,-1,1,-1,1,-1 };
string dir[8] = { "R","L","D","U","RD","RU","LD","LU" };
char c[10][10];

//long longしか使わない
//素数は1より大きい
//lower_boundは指定したkey以上の要素の一番左のイテレータをかえす
//upper_boundは指定したkeyより大きい要素の一番左のイテレータをかえす
int main() {
	ll n, k;
	cin >> n >> k;
	vector<ll>a(n);
	rep(i, n) {
		cin >> a[i];
	}
	ll ans = INF;
	for (ll bits = 0;bits < (1 << n);++bits) {
		ll kazu = 0;
		ll res = 0;
		vector<ll>target;
		for (ll i = 0;i < n;++i) {
			if (bits & (1 << i)) {
				kazu++;
				target.push_back(i);
			}
		}
		if (kazu >= k) {
			vector<ll>a2(n);
			rep(i, n) {
				a2[i] = a[i];
			}
			for (ll i = 0;i < target.size();++i) {
				ll target2 = target[i];
				ll hmax = 0;
				for (ll j = 0;j < target2;++j) {
					hmax = max(hmax, a2[j]);
				}
				res += max((ll)0, hmax + 1 - a2[target2]);
				if (a2[target2] <= hmax + 1)a2[target2] = hmax + 1;
			}
			ans = min(ans, res);
		}
	}
	cout << ans << endl;
	return 0;
}
