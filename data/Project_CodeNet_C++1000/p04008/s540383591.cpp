/*
	Teleporter
	https://atcoder.jp/contests/agc004/tasks/agc004_d
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
#else
	#define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

const int N = 100100;
int n, k;
int ans;
vector<int> g[N];

int dfs(int v) {
	int x = 0;
	for (int u : g[v]) {
		int y = dfs(u);
		if (v != 0 && y == k)
			ans++;
		else
			x = max(x, y);
	}
	return x + 1;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		int v;
		scanf("%d", &v);
		v--;
		if (i == 0) {
			if (v) ans++;
			continue;
		}
		g[v].push_back(i);
	}
	dfs(0);
	printf("%d\n", ans);

	return 0;
}
