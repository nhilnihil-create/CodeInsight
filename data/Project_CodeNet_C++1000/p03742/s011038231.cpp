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
#include <queue>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/*
const ll MOD = (ll)1e9 + 7;
ll add(ll x, ll y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
ll sub(ll x, ll y) {
	x -= y;
	if (x < 0) return x + MOD;
	return x;
}
ll mult(ll x, ll y) {
	return (x * y) % MOD;
}
*/

const int N = 50;
bool a[N][N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	ll x, y;
	scanf("%lld%lld", &x, &y);
	if (abs(x - y) <= 1) {
		printf("Brown\n");
	} else {
		printf("Alice\n");
	}
	return 0;

	for (int s = 1; s < N; s++) {
		for (int x = 0; x <= s; x++) {
			int y = s - x;
			for (int i = 1; 2 * i <= x; i++)
				a[x][y] |= !a[x - 2 * i][y + i];
			for (int i = 1; 2 * i <= y; i++)
				a[x][y] |= !a[x + i][y - 2 * i];
		}
	}
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			printf("%d", (int)a[i][j]);
		}
		printf("\n");
	}

	return 0;
}
