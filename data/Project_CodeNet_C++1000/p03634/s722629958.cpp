#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<functional>
#include<algorithm>
#include<stdlib.h>
#include<string>
#include<string.h>
#define _USE_MATH_DEFINES
#include<math.h>
#include<deque>
#include<set>
#include<map>
#include<queue>
#include<list>
#include<iostream>
#include <bitset>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(auto i=a;i<b;i++)
#define all(_x) _x.begin(), _x.end()
#define r_sort(_x) sort(_x.begin(), _x.end(), std::greater<int>())
#define vec_cnt(_a, _n) (upper_bound(all(_a), _n) - lower_bound(all(_a), _n))
#define vec_unique(_a) _a.erase(std::unique(all(_a)), _a.end());
#define vvec vector<vector<ll>>
ll gcd(ll a, ll b) { return a % b == 0 ? b : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
const int mod = 998244353;
ll power(ll x, ll p) { ll a = 1; while (p > 0) { if (p % 2 == 0) { x *= x; p /= 2; } else { a *= x; p--; } }return a; }
ll mpower(ll x, ll p) { ll a = 1; while (p > 0) { if (p % 2 == 0) { x = x * x % mod; p /= 2; } else { a = a * x % mod; p--; } }return a; }
ll c(ll n, ll k) { ll a = 1; rep(i, 1, k) { a *= n - i + 1; a /= i; }return a; }
ll mc(ll n, ll m) { ll k = 1, l = 1; rep(i, n - m + 1, n + 1) k = k * i % mod; rep(i, 1, m + 1) l = l * i % mod; l = mpower(l, mod - 2); return k * l % mod; }
#define MAX 100010
struct edge { int to; ll cost; };
vector<edge> G[MAX];
ll depth[MAX];
void dfs(int v, int p, ll d) {
	depth[v] = d;
	rep(i, 0, G[v].size()) {
		if(G[v][i].to != p)dfs(G[v][i].to, v, d + G[v][i].cost);
	}
}
void init(int root, int V) {
	dfs(root, -1, 0);
}
int main() {
	int N, Q, a, b, c, K;
	vector<ll> ans;
	scanf("%d", &N);
	rep(i, 0, N - 1)scanf("%d%d%d", &a, &b, &c), a--, b--, G[a].push_back({ b, c }), G[b].push_back({ a, c });
	scanf("%d%d", &Q, &K);
	K--;
	init(K, N);
	rep(i, 0, Q) {
		scanf("%d %d", &a, &b);
		a--, b--;
		ans.push_back(depth[a] + depth[b]);
	}
	rep(i, 0, Q)printf("%lld\n", ans[i]);
	return 0;
}