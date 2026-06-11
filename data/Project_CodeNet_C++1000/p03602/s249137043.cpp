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

ll gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
vector<int> lat[100010];
vector<int> pet[100010];
bool rel[100010];
bool lal[100010];
void rec(int pe) {

	rel[pe] = true;
	for (int c : pet[pe])
	{
		if (lal[c]) continue;
		lal[c] = true;
		for (int ne : lat[c])
		{
			if (rel[ne]) continue;
			rec(ne);
		}
	}
}
void Solve() {
	
	int n;
	cin >> n;
	ll orit[301][301];
	ll wt[301][301];
	for (size_t i = 1; i <= n; i++)
	{
		for (size_t j = 1; j <= n; j++)
		{
			cin >> orit[i][j];
			wt[i][j] = orit[i][j];
		}
	}
	bool find[301][301];
	for (size_t i = 1; i <= n; i++)
	{
		for (size_t j = 1; j <= n; j++)
		{
			find[i][j] = false;
		}
	}

	for (size_t i = 1; i <= n; i++)
	{
		for (size_t j = 1; j <= n; j++)
		{
			for (size_t k = 1; k <= n; k++)
			{

				if (j != i && i != k && wt[j][k] == wt[j][i] + wt[i][k]) {
					find[j][k] = true;
				}
				wt[j][k] = min(wt[j][k], wt[j][i] + wt[i][k]);
			}
		}
	}

	ll res = 0;
	for (size_t i = 1; i <= n; i++)
	{
		for (size_t j = i + 1; j <= n; j++)
		{
			if (orit[i][j] > wt[i][j]) {
				cout << -1 << endl;
				return;
			}
			res += find[i][j] ? 0 : wt[i][j];
		}
	}
	cout << res << endl;
}


int main() {
	Solve();
	return 0;
}

