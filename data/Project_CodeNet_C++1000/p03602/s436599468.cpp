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
using namespace std;
using LL = long long;
using ULL = unsigned long long;
constexpr long long MOD = 1000000000 + 7;
constexpr long long INF = 1e17 - 10;
const double PI = acos(-1);
#define fir first
#define sec second
typedef pair<LL, LL> Pll;
typedef pair<LL, pair<LL, LL>> Ppll;
typedef pair<LL, pair<LL, bitset<100001>>> Pbll;
typedef pair<LL, pair<LL, vector<LL>>> Pvll;
typedef pair<LL, LL> Vec2;
struct Tll { LL first, second, third; };
typedef pair<LL, Tll> Ptll;
#define rep(i,rept) for(LL i=0;i<rept;i++)
#define Mfor(i,mf) for(LL i=mf-1;i>=0;i--)
LL h, w, n, m, s, k, ans, sum, a[1000000], d[10000];
bool f;
struct Edge { LL to, cost; };
vector<Edge>vec[10000];
string str;
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
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
void DIUX(LL s) {
	for (int i = 0; i < 10000; i++)
		d[i] = INF;
	d[s] = 0;
	priority_queue<Pll, vector<Pll>, greater<Pll>> pq;
	pq.push(make_pair(d[s], s)); // (cost,頂点番号) 
	while (!pq.empty()) {
		Pll pp;
		pp = pq.top();
		LL cos = pp.first, vv = pp.second;
		pq.pop();
		if (d[vv] < pp.first)continue;
		for (int i = 0; i < vec[vv].size(); i++) {
			if (vec[vv][i].cost + d[vv] < d[vec[vv][i].to]) {
				d[vec[vv][i].to] = vec[vv][i].cost + d[vv];
				pq.push(make_pair(d[vec[vv][i].to], vec[vv][i].to));
			}
		}
	}
}

int main() {
	cin >> n;
	rep(i,n)
		rep(j, n) {
		LL x;
		cin >> x;
		vec[i].push_back(Edge{ j,x });
		ans += x;
	}
	rep(i, n) {
		DIUX(i);
		rep(j, n) {
			if (vec[i][j].cost != d[j])
				f = 1;
		}
	}
	if (f){
		cout << -1 << endl;
		return 0;
	}
	else {
		rep(i, n)
			rep(j, n) {
			bool F = 0;
			rep(k, n) 
				if (k != i&&k != j)
					if (vec[i][j].cost == vec[i][k].cost + vec[j][k].cost)
						F = 1;
				if (F)ans -= vec[i][j].cost;
		}
	}
		cout << ans/2 << endl;
	return 0;
}
