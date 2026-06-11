#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <stdio.h>
#include <tuple>
#include <bitset>
#include <cfloat>
#include <fstream>
#include <limits.h>
#include <list>
#include <math.h>
#include <random>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <numeric>
#include <utility>
#include <sstream>
// *テンプレート*
#define int long long
#define rep(i, n) for (int i = 0; i < (n); i++)
#define P pair<int, int>
#define sz(x) x.size()
// aよりbの方が小さかったら、aの値をbの値に置き換える。(swapではない！)
template<class T> inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
// aよりbの方が大きかったら、aの値をbの値に置き換える。
template<class T> inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

using namespace std;
typedef long long ll;
using Graph = vector<vector<int>>;
//最大公約数
ll gcd(ll a, ll b) {
	if (a < b)swap(a, b);
	if (b == 0) return a;
	return gcd(b, a % b);
}
//最小公倍数
ll lcm(ll a, ll b) {
	ll g = gcd(a, b);
	return a / g * b;
}
// 素数かどうか判定
bool prime(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n%i == 0)return false;
	}
	return n != 1;
}


const long long MOD = 1000000007;
const long long INF = 1LL << 60;
// *テンプレートここまで*

// pair -> vector<pair<int,int>> 
//		   AandB.push_back(make_pair(a[i],b[i]))

inline int nCr(int n, int r) {
	int res = 1;
	vector<bool>done(r, false);
	for (int i = n; i > n - r; i--) {
		res *= i;
		for (int j = 1; j <= r; j++) {
			if (res%j == 0 && !done[j - 1]) {
				res /= j; done[j - 1] = true;
			}
		}
	}
	return res;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, a, b; cin >> n >> a >> b;
	vector<int>v(n); rep(i, n)cin >> v[i];
	sort(v.rbegin(), v.rend());
	int sum = 0;
	int last = v[a - 1];
	rep(i, a) {
		sum += v[i];
	}
	cout << fixed << setprecision(20) << 1.*sum / a << endl;
	if (last == v.front()) {
		int cnt = 0;
		rep(i, n) {
			if (v[i] == last)cnt++;
		}
		int ans = 0;
		for (int i = a; i <= b; i++) {
			ans += nCr(cnt, i);
		}
		cout << ans << endl;
	}
	else {
		int cnt = 0;
		int cnt2 = 0;
		rep(i, a) {
			if (v[i] == last)cnt++;
		}
		rep(i, n) {
			if (v[i] == last)cnt2++;
		}
		cout << nCr(cnt2, cnt) << endl;
	}
	return 0;
}