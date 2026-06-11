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

const int N = 100100;
pll a[N];
int n;
ll ans[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i].first);
		a[i].second = i;
	}
	sort(a, a + n);
	reverse(a, a + n);
	a[n].first = 0;
	int m = n;
	for (int i = 1; i <= n; i++) {
		m = min(m, (int)a[i - 1].second);
		ans[m] += (a[i - 1].first - a[i].first) * i;
	}
	for (int i = 0; i < n; i++)
		printf("%lld\n", ans[i]);

	return 0;
}
