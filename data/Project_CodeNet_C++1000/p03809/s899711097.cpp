/*
cat <<EOF >mistaken-paste
*/

#pragma GCC diagnostic ignored "-Wincompatible-pointer-types"
#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define BIG 2000000007
#define VERYBIG 200000000000007LL

#define MOD 1000000007
typedef uint64_t ull;
typedef  int64_t sll;

#define N_MAX 300000
#define M_MAX 200000

#include <queue>
#include <stack>
// #include <tuple>
#include <set>
#include <map>

// using namespace std; // HELL
using std::queue;
using std::priority_queue;
using std::stack;
// using std::tuple;
using std::set;
using std::map;
using std::vector;
using std::greater;
using std::pair;

typedef struct {
	int32_t a;
	int32_t b;
} hw;

typedef struct {
	sll a;
	sll b;
} hwll;

typedef struct {
	hwll a;
	hwll b;
} linell;


typedef struct {
	ull s;
	ull t;
	int32_t c;
} struct_a;

typedef struct {
	int32_t from;
	int32_t to;
	sll cost;
} struct_b;

ull n, m;
ull h, w;
ull k;
ull q;
ull vua, vub, vuc, vud, vue, vuf;
sll vsa, vsb, vsc, vsd, vse, vsf;
long double vra, vrb, vrc;
double vda, vdb, vdc;
size_t slen;
size_t tlen;
char ch, dh;


ull umin (ull x, ull y) {
	return (x < y) ? x : y;
}

ull umax (ull x, ull y) {
	return (x > y) ? x : y;
}

sll smin (sll x, sll y) {
	return (x < y) ? x : y;
}

sll smax (sll x, sll y) {
	return (x > y) ? x : y;
}

typedef struct {
	int32_t to;
	sll cost;
} edge;
typedef pair<sll, int32_t> P;

std::vector<edge> g[N_MAX];
void dijk_init (ull n, struct_b arr[]) {
	edge x;
	for (int32_t i = 0; i < n; i++) {
		x.to = arr[i].to;
		x.cost = arr[i].cost;
		g[arr[i].from].push_back(x);
	}
}

bool dijkstra (int s, sll distance[]) {
	priority_queue<P, std::vector<P>, greater<P> > que; // (最短距離, 頂点番号)
	que.push(P(distance[s], s));

	bool ischanged = false;
	while (!que.empty()) {
		P p = que.top();
		que.pop();

		sll v = p.second;
		if (distance[v] < p.first) continue;

		int32_t maxsize = g[v].size();
		for (int32_t i = 0; i < maxsize; i++) {
			edge e = g[v][i];
			if (distance[e.to] > distance[v] + e.cost) {
				distance[e.to] = distance[v] + e.cost;
				ischanged = true;
				que.push(P(distance[e.to], e.to));
			}
		}
	}

	return ischanged;
}

sll dist[N_MAX];
struct_b path[M_MAX * 2];

sll a[N_MAX];
sll dp[N_MAX + 1];
hwll arr[M_MAX];

ull solve () {
	sll i, j, ki;
	// ull result = 0;
	sll result = 0;
	// double result = 0;
	ull maybe = 0;
	// sll maybe = 0;
	// ull sum = 0;
	sll sum = 0;
	ull item;
	ull *dpcell;

	if (n == 2) {
		if (a[0] == a[1]) {
			puts("YES");
			return 0;
		} else {
			puts("NO");
			return 1;
		}
	}

	for (i = 0; i < n - 1; i++) {
		dp[arr[i].a]++;
		dp[arr[i].b]++;

		path[i].from = path[i + (n - 1)].to = arr[i].a;
		path[i].to = path[i + (n - 1)].from = arr[i].b;
		path[i].cost = path[i + (n - 1)].cost = 1;
	}
	dijk_init((n - 1) * 2, path);
	ull root = 0;
	for (i = 0; i < n; i++) {
		// printf("%llu: %llu\n", i, dist[i]);
		if (dp[root] < dp[i]) root = i;
	}

	// printf("root: %llu\n", root);

	for (i = 0; i < n; i++) {
		dist[i] = BIG;
	}
	dist[root] = 0;
	dijkstra(root, dist);

	priority_queue<P, vector<P> > vq;
	for (i = 0; i < n; i++) {
		vq.push(P(dist[i], i));
	}

	while (!vq.empty()) {
		sll v = vq.top().second;
		vq.pop();

		// printf("%lld:\n", v);

		bool isleaf = true;
		sll sum = 0;
		sll maxval = 0;
		for (edge x : g[v]) {
			sll vv = x.to;
			if (dist[vv] < dist[v]) continue;
			isleaf = false;

			// printf("\t+[%lld]:%llu\n", vv, dp[vv]);

			sum += dp[vv];
			maxval = umax(maxval, dp[vv]);
		}

		if (isleaf) {
			dp[v] = a[v];
			continue;
		}

		// sll ret = sum - a[v];
		// sll pass = a[v] - ret;
		sll pass = a[v] * 2 - sum;
		sll ret = a[v] - pass;
		// printf("return: %lld, pass: %lld\n", ret, pass);
		if (ret < 0 || pass < 0) goto fail;

		sll returnlim = umin(sum / 2, sum - maxval);
		if (ret > returnlim) goto fail;

		dp[v] = pass;
	}

	if (dp[root]) goto fail;

	goto success;

	return 0;

	success:
	puts("YES");
	return 0;

	fail:
	puts("NO");
	return 1;
}

int32_t main (void) {
	int32_t i, j;
	int32_t x, y;

	scanf("%llu", &n, &m);
	for (i = 0; i < n; i++) {
		scanf("%llu", &a[i]);
	}
	for (i = 0; i < n - 1; i++) {
		scanf("%llu", &arr[i].a);
		scanf("%llu", &arr[i].b);
		arr[i].a--;
		arr[i].b--;
	}

	solve();

	return 0;
}
