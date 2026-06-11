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
long long MOD = 1000000000 + 7;// 998244353;// ;
constexpr long long INF = numeric_limits<LL>::max() / 2;
const double PI = acos(-1);
#define fir first
#define sec second
#define thi third
#define debug(x) cerr<<#x<<": "<<x<<'\n'
typedef pair<LL, LL> Pll;
typedef pair<LL, pair<LL, LL>> Ppll;
typedef pair<LL, pair<LL, bitset<100001>>> Pbll;
typedef pair<LL, pair<LL, vector<LL>>> Pvll;
typedef pair<LL, LL> Vec2;
struct Tll { LL first, second, third; };
struct Fll { LL first, second, third, fourd; };
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
struct edge { LL from, to, cost; };
vector<vector<LL>>g;
vector<edge>edges;
vector<LL>v;
map<LL, LL>ma;
set<Pll>st;
LL h, w, n, m, k, t, s, p, q, last, cnt, sum, ans, dp[210000], a[210000], b[210000];
string str, ss;
bool f;
char c;
LL gcd(LL a, LL b) {
	if (a < b) gcd(b, a);
	LL r;
	while ((r = a % b)) {
		a = b;
		b = r;
	}
	return b;
}
int main() {
	cin >> n;
	rep(i, n) {
		cin >> a[i];
		if (a[i] % 2 == 0)cnt++;
	}
	while (true) {
		if (cnt % 2 == 1) {
			break;
		}
		LL mn = INF, sum = 0;
		rep(i, n) {
			mn = min(a[i], mn);
			sum += a[i] - 1;
		}
		if (mn == 1) {
			if (mn % 2 == 1)f ^= 1;
			break;
		}
		cnt = 0;
		rep(i, n) 
			if (a[i] % 2 == 1 && a[i] != 1) {
				a[i]--;
				break;
			}
		LL g = a[0];
		rep(i, n) {
			g = gcd(g, a[i]);
		}
		rep(i, n) {
			a[i] /= g;
			if (a[i] % 2 == 0)cnt++;
		}
		f ^= 1;
	}
	if (f == 0)cout << "First" << endl;
	else cout << "Second" << endl;
	return 0;
}