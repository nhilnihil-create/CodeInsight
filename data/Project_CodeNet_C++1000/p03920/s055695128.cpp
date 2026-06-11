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
const long long mod = 1000000007;
const long long INF = 1LL << 60;
// *テンプレートここまで*

// pair -> vector<pair<int,int>> 
//		   AandB.push_back(make_pair(a[i],b[i]))


signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += i;
		if (sum > n) {
			int tmp = sum - n;
			for (int j = 1; j <= i; j++) {
				if (j == tmp)continue;
				cout << j << endl;
			}
			return 0;
		}
		if (sum == n) {
			for (int j = 1; j <= i; j++) {
				cout << j << endl;
			}
			return 0;
		}
	}
	return 0;
}