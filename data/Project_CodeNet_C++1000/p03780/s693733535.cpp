#pragma once
#include <stdio.h>
#include <sstream>
#include <string>
#include <string.h>
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
#include <limits>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define bit(x,v) ((ll)x << v)

const ll INF = 1000000007;
const int MAX = 210000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
int pr[100010];
void uini(int n) {
	for (size_t i = 0; i <= n; i++)
	{
		pr[i] = i;
	}
}

int parent(int x) {
	if (x == pr[x]) return x;
	return pr[x] = parent(pr[x]);
}

bool unit(int x, int y) {
	int px = parent(x);
	int py = parent(y);

	if (px == py) return false;
	if (px < py) {
		pr[py] = px;
	}
	else {
		pr[px] = py;
	}
	return true;
}

// res[i][c] := i 文字目以降で最初に文字 c が登場する index (存在しないときは n)
vector<vector<int> > calcNext(const string& S) {
	int n = (int)S.size();
	vector<vector<int> > res(n + 1, vector<int>(26, n));
	for (int i = n - 1; i >= 0; --i) {
		for (int j = 0; j < 26; ++j) res[i][j] = res[i + 1][j];
		res[i][S[i] - 'a'] = i;
	}
	return res;
}
// mod 1000000007 の世界で a += b する関数
void add(long long& a, long long b) {
	a += b;
	if (a >= MOD) a -= MOD;
}

void solv() {
	int n, k;
	cin >> n >> k;
	map<ll, int> mp;
	int kind = 0;
	for (size_t i = 0; i < n; i++)
	{
		ll a;
		cin >> a;
		mp[a]++;
		if (mp[a] == 1)kind++;
	}

	pair<ll, int> pr[5010];
	int p = 0;
	for (auto mv : mp)
	{
		pr[p++] = mv;
	}

	sort(pr, pr + kind, greater<pair<ll, int>>());
	ll dp[5010][6000];
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	ll find = 0;
	int pi = 1;
	for (size_t i = 1; i <= kind; i++)
	{
		for (size_t j = 0; j < 6000; j++)
			dp[pi][j] = dp[pi - 1][j];

		if (pr[i - 1].first >= k) { 
			find = i;
			pi++;
			continue; 
		}

		ll v = pr[i - 1].first;
		for (size_t inn = 0; inn < pr[i - 1].second; inn++)
		{
			for (size_t j = 0; j < 6000; j++)
				dp[pi][j] = dp[pi - 1][j];

			for (size_t j = 1; j < 6000; j++)
			{
				if (j - v < 0) continue;
				if (dp[pi - 1][j - v] == 0) continue;
				dp[pi][j] += dp[pi - 1][j - v];
				if (j - v < k && j >= k) find = i;
			}
			pi++;
		}

	}
	int res = 0;
	for (size_t i = find; i < kind; i++)
	{
		res += pr[i].second;
	}

	cout << res << endl;
}

int main() {
	//COMinit();
	solv();

	return 0;
}
