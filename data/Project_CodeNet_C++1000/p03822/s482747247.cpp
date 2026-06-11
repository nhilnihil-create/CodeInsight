#include <cmath>
#include <cstdio>
#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <stdio.h>
#include <functional>
#include <chrono>
using namespace std;

#define rep(i,s,n) for(ll i=s;i<(n);++i)
using ll = long long;
using pll = pair<ll, ll>;
constexpr ll INF = (1LL << 60);
constexpr ll MOD = (1e9 + 7);
//constexpr ll MOD = (998244353);

using vl = vector<ll>;
using vvl = vector<vector<ll>>;

template<class T>
vector<vector<T>> vvt(T init, ll m, ll n) {
	vector<vector<T>> ans = vector<vector<T>>(m, vector<T>(n, init));
	return move(ans);
}

template<class T>
vector<T> vt(T init,ll n) {
	vector<T> ans = vector<T>(n, init);
	return move(ans);
}

template<class T>
T maxVec(vector<T> &v) {
	T ans = -INF;
	rep(i,0, v.size()) {
		ans = max(ans, v[i]);
	}
	return ans;
}

// 素数判定
bool judge(ll n) {
	for (ll i = 2; i * i <= n; i++) if (n %= i)return false;
	return true;
}


template <class C>
void print(const C& c, std::ostream& os = std::cout)
{
	std::copy(std::begin(c), std::end(c), std::ostream_iterator<typename C::value_type>(os, ", "));
	os << std::endl;
}

ll count(ll n,ll r) {
	ll ans = 0,check = 1;
	rep(i,0, r) {
		if ((n & check) > 0) {
			ans++;
		}
		check = check << 1;
	}
	return ans;
}

bool sortreverse(ll a, ll b) {
	return a > b;
}

bool kansu(pll a, pll b) {
	return a.first < b.first;
}

ll kiriage(ll a, ll b) {
	if (a % b == 0)return a / b;
	return a / b + 1;
}

ll dp[100000 + 5];

ll solv(ll n,vvl &graph) {
	if (dp[n] != 0)return dp[n];
	if (graph[n].size() == 0) {
		dp[n] = 1; return 1;
	}
	//printf("%lld\n", n);
	vl kari(graph[n].size());
	rep(i,0,kari.size()) {
		kari[i] = solv(graph[n][i], graph);
	}
	sort(kari.begin(), kari.end(),sortreverse);
	ll res = 0;
	rep(i, 0, kari.size()) {
		res = max(res, i + 1 + kari[i]);
	}
	dp[n] = res;
	return res;
}

int main() {
	ll n;
	cin >> n;
	vl a(n,0);
	vvl graph(n);
	rep(i, 0, n - 1) {
		cin >> a[i];
		graph[a[i] - 1].push_back(i + 1);
		//graph[i + 1].push_back(a[i] - 1);
	}
	ll ans = solv(0, graph);
	printf("%lld\n", ans - 1);
}