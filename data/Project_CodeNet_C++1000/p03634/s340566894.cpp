#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <list>
#include <unordered_set>
#include <tuple>
#include <cmath>
#include <limits>
#include <type_traits>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <set>
#include <bitset>
#include <regex>
#include <random>
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define rep(i,n)for(ll i=0;i<n;++i)
#define exout(x) printf("%.10f\n", x)
const double pi = acos(-1.0);
const ll MOD = 1000000007;
const ll INF = 1e18;
const ll MAX_N = 201010;

//最大公約数
ll gcd(ll x, ll y) {
	return y ? gcd(y, x % y) : x;
}

ll lcm(ll x, ll y) {
	if (x == 0 || y == 0)return 0;
	return (x / gcd(x, y) * y);
}

ll dx[4] = { 0,0,-1,1 };
ll dy[4] = { -1,1,0,0 };
ll ans[110][110];
bool flag[2][110];
using edge = struct { ll to;ll cost; };
vector<edge>tree[101010];
ll depth[101010];

void dfs(ll v, ll p, ll d) {
	depth[v] = d;
	for (auto nv : tree[v]) {
		if (nv.to == p)continue;
		dfs(nv.to, v, d + nv.cost);
	}
}

//long longしか使わない
//素数は1より大きい
//lower_boundは指定したkey以上の要素の一番左のイテレータをかえす
//upper_boundは指定したkeyより大きい要素の一番左のイテレータをかえす
int main() {
	ll n;
	cin >> n;
	rep(i, n-1) {
		ll a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		tree[a].push_back({ b,c });
		tree[b].push_back({ a,c });
	}
	ll q, k;
	cin >> q >> k;
	k--;
	dfs(k, -1, 0);
	rep(i, q) {
		ll x, y;
		cin >> x >> y;
		x--, y--;
		cout << depth[x] + depth[y] << endl;
	}
	return 0;
}
