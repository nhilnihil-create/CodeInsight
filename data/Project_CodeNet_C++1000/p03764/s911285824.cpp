#pragma once
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <deque>
#include <numeric>
#include <iomanip>
#define M_PI acos(-1)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1000000007;
const int MAX_V = 201;
int now = 0;

const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

// 二項係数計算
long long COM(int n, int k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
struct edge {
	int t;
	edge(int _t) : t(_t) {}
};
bool use[100010];


vector<edge> te[100010];
vector<edge> fe[100010];
int d[100100];
ll rec(int num) {
	if (num == 0) return 0;
	return rec(num - 1) + num;
}
ll gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

ll calc(ll b,ll n){
	if (n < b) return n;
	return calc(b, n / b) + n % b;
}

void Solve() {

	int n, m;
	cin >> n >> m;
	ll nsum = 0;
	ll bef;
	for (size_t i = 0; i < n; i++)
	{
		
		ll x;
		cin >> x;
		if (i == 0) {
			bef = x;
			continue;
		}
		ll add = ((n - 1) - (i - 1)) * i;
		add %= INF; 
		add *= x - bef;
		add %= INF;
		nsum += add;
		nsum %= INF;
		bef = x;
	}
	ll msum = 0;
	for (size_t i = 0; i < m; i++)
	{
		ll x;
		cin >> x;
		if (i == 0) {
			bef = x;
			continue;
		}
		ll add = ((m - 1) - (i - 1)) * (i);
		add %= INF;
		add *= x - bef;
		add %= INF;
		msum += add;
		msum %= INF;
		bef = x;
	}
	ll res = nsum * msum;
	res %= INF;
	cout << res << endl;
}


int main() {
	Solve();
	return 0;
}

