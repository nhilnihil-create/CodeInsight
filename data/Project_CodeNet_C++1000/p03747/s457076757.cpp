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
// *テンプレート*
#define int long long
#define rep(i, n) for (int i = 0; i < (n); i++)
#define P pair<int, int>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long MOD = 1000000007;
const long long INF = (1LL << 29);
using namespace std;
typedef long long ll;
map<int, int> mp;
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

// *テンプレートここまで*

// pair -> vector<pair<int,int>> 
//		   AandB.push_back(make_pair(a[i],b[i]))


signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, l, t;
	cin >> n >> l >> t;
	vector<int>x(n), w(n);
	rep(i, n)cin >> x[i] >> w[i];
	vector<int>tmp(n);
	rep(i, n) {
		if (w[i] == 1)tmp[i] = (x[i] + t) % l;
		else tmp[i] = ((x[i] - t) % l + l) % l;
	}
	sort(tmp.begin(), tmp.end());
	int cnt = 0;
	rep(i,n) {
		if (w[i] == 1)cnt -= (t - (l - x[i]) + l) / l;
		else cnt += (t - (x[i] + 1) + l) / l;
	}
	cnt = (cnt%n + n) % n;
	vector<int>ans(n);
	rep(i, n) {
		ans[(i + cnt) % n] = tmp[i];
	}
	rep(i, n) {
		cout << ans[i] << endl;
	}
	return 0;
}