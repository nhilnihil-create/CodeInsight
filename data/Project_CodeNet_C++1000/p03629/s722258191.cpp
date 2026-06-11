# include <iostream>
# include <algorithm>
#include <array>
# include <cassert>
#include <cctype>
#include <climits>
#include <numeric>
# include <vector>
# include <string>
# include <set>
# include <map>
# include <cmath>
# include <iomanip>
# include <functional>
# include <tuple>
# include <utility>
# include <stack>
# include <queue>
# include <list>
# include <bitset>
# include <complex>
# include <chrono>
# include <random>
# include <limits.h>
# include <unordered_map>
# include <unordered_set>
# include <deque>
# include <cstdio>
# include <cstring>
#include <stdio.h>
#include<time.h>
#include <stdlib.h>
#include <cstdint>
#include <cfenv>
#include<fstream>
//#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const long long MOD = 1000000000 + 7;//1000000000 + 7 998244353 924844033 1000000000 + 9;
constexpr long long INF = 1LL << 60;//numeric_limits<LL>::max();
const double PI = acos(-1);
#define fir first
#define sec second
#define thi third
#define debug(x) cerr<<#x<<": "<<x<<'\n'
typedef pair<LL, LL> Pll;
typedef pair<double, double> Dll;
typedef pair<LL, pair<LL, LL>> Ppll;
typedef pair<LL, pair<LL, bitset<100001>>> Pbll;
typedef pair<LL, pair<LL, vector<LL>>> Pvll;
typedef pair<LL, LL> Vec2;
struct Tll { LL first, second, third; };
struct Fll { LL first, second, third, fourth; };
typedef pair<LL, Tll> Ptll;
#define rep(i,rept) for(LL i=0;i<rept;i++)
#define Rrep(i,mf) for(LL i=mf-1;i>=0;i--)
void YN(bool f) {
	if (f)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}
void yn(bool f) {
	if (f)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}
struct Edge { LL to, cost; };
struct edge {
	LL from, to, cost;
};
vector<vector<Edge>>g;
vector<edge>ed;
vector<Pll>pv;
set<LL>st;
map<Pll, LL>ma;
int di[4][2] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };
string str, ss;
bool f[200000];
LL n, m, s, t, h, w, k, q, p, ans, sum, cnt, a[210000], b[210000], 
nex[210000][26],dp[210000];
int main() {
	cin >> str;
	rep(i, 26)nex[str.size()][i] = str.size() + 1;
	rep(j, str.size() + 1)dp[j] = INF;
	dp[str.size()+1] = 0;
	Rrep(i, str.size()) {
		rep(j, 26) {
			nex[i][j] = nex[i + 1][j];
		}
		nex[i][str[i] - 'a'] = i + 1;
	}
	Rrep(i, str.size()) {
		rep(j, 26) {
			dp[i] = min(dp[nex[i][j]] + 1, dp[i]);
		}
	}
	LL cur = 0;
	while (cur != str.size()+1) {
		LL ne = 0, eval = INF;
		Rrep(i, 26) {
			if (eval >= dp[nex[cur][i]]) {
				eval = dp[nex[cur][i]];
				ne = i;
			}
		}
		ss.push_back(ne + 'a');
		cur = nex[cur][ne];
	}
	cout << ss << endl;
	return 0;
}