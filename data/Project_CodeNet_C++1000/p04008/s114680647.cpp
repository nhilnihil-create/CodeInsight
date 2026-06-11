#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cfloat>
#include <complex>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <list>
#include <map>
#include <math.h>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <string.h>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
#define int long long
#define ll long long
#define eps LDBL_EPSILON
#define mod (int)1000000007
#define DBLINF (DBL_MAX)/10
#define P pair<int,int>
#define prique(T) priority_queue<T,vector<T>,greater<T>>
#define all(V) V.begin(),V.end()
#ifdef int
constexpr int INF = LLONG_MAX / 10;
#else
constexpr int INF = INT_MAX / 10;
#endif
template <class T, class U>
inline bool chmax(T& lhs, const U& rhs) {
	if (lhs < rhs) {
		lhs = rhs;
		return 1;
	}
	return 0;
}
template <class T, class U>
inline bool chmin(T& lhs, const U& rhs) {
	if (lhs > rhs) {
		lhs = rhs;
		return 1;
	}
	return 0;
}
using namespace std;
inline int gcd(int a, int b) {
	while (b) {
		int c = a;
		a = b; b = c % b;
	}
	return a;
}
inline int lcm(int a, int b) {
	return a / gcd(a, b) * b;
}
bool isprime(int n) {
	if (n == 1)return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0)return false;
	}
	return true;
}
int mypow(int a, int b) {
	if (!b)return 1;
	if (b & 1)return mypow(a, b - 1) * a;
	int memo = mypow(a, b >> 1);
	return memo * memo;
}
int modpow(int a, int b, int m = mod) {
	if (!b)return 1;
	if (b & 1)return modpow(a, b - 1, m) * a % m;
	int memo = modpow(a, b / 2, m);
	return memo * memo % m;
}
int n, k, a[100010];
vector<int> vec[100010];
int dist[100010];
void dfs(int node) {
	for (int i : vec[node]) {
		if (i != 1) {
			dist[i] = dist[node] + 1;
			dfs(i);
		}
	}
}
signed main() {
	cin >> n >> k;
	REP(i, n) {
		cin >> a[i];
		if (i != 1)vec[a[i]].push_back(i);
	}
	int ans = 0;
	if (a[1] != 1)ans++;
	a[1] = 1;
	dfs(1);
	priority_queue<P> que;
	REP(i, n) {
		if (vec[i].empty())que.push(make_pair(dist[i], i));
	}
	while (!que.empty()) {
		P p = que.top();
		que.pop();
		if (dist[p.second] <= k)continue;
		rep(i, k - 1) {
			if (dist[p.second] <= k - i)goto end;
			dist[p.second] = k - i;
			p.second = a[p.second];
			if (p.second == 1)goto end;
		}
		if (a[p.second] == 1)goto end;
		que.push(make_pair(dist[a[p.second]], a[p.second]));
		a[p.second] = 1;
		ans++;
	end:;
	}
	cout << ans << endl;
	return 0;
}