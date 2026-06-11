#include <iostream>
#include <cstdio>
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <stdlib.h>
#include <functional>
#include <string>
#include <list>
#include <fstream>
#include <iomanip>
#include <array>
#include <map>
#include <queue>
#include <limits.h>
#include <set>
#include <stack>
#include <random>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <chrono>
#include <bitset>
#define rep(i,s,n) for(int i = (s); (n) > i; i++)
#define REP(i,n) rep(i,0,n)
#define RANGE(x,a,b) ((a) <= (x) && (x) <= (b))
#define DUPLE(a,b,c,d) (RANGE(a,c,d) || RANGE(b,c,d) || RANGE(c,a,b) || RANGE(d,a,b))
#define INCLU(a,b,c,d) (RANGE(a,c,d) && (b,c,d))
#define PW(x) ((x)*(x))
#define ALL(x) (x).begin(), (x).end()
#define MODU 1000000007
#define bitcheck(a,b)   ((a >> b) & 1)
#define bitset(a,b)      ( a |= (1 << b))
#define bitunset(a,b)    (a &= ~(1 << b))
#define MP(a,b) make_pair((a),(b))
#define Manh(a,b) (abs((a).first-(b).first) + abs((a).second - ((b).second))
#define pritnf printf
#define scnaf scanf
#define itn int

#include <nmmintrin.h>
#ifdef _MSC_VER

#define __builtin_popcount _mm_popcnt_u32
#define __builtin_popcountll _mm_popcnt_u64
#endif
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T &val) {
	std::fill((T*)array, (T*)(array + N), val);
}

struct Edge {
	int from, to, w;
};
  
class SegmentTree {//基本的に半開区間 [a,b)
public:
	vector<int> data;
	int n = 1;
	SegmentTree(int a) {
		while (n < a) n *= 2;
		data = vector<int>(n * 2 - 1, 0);
	}
	void update(int p, int a) {
		int cur = p + n - 1;
		while (cur) {
			data[cur] += a;
			cur = (cur - 1) / 2;
		}
		data[0] = a;
	}
	int sum(int a, int b, int num = 0, int base = 1) {
		int l = (num + 1 - base) * (n / base), r = l + n / base;

		if (a == l && b == r)
			return data[num];
		int nr = (l + r) / 2;
		int ret = 0;
		if (nr > a) ret += sum(a, min(b, nr), num * 2 + 1, base * 2);
		if (nr < b) ret += sum(max(a, nr), b, num * 2 + 2, base * 2);
		return ret;
	}
};

struct UnionFind {
	vector<int> data;
	UnionFind(int size) : data(size, -1) { }
	bool unionSet(int x, int y) { //ｘの入ってる集合と yの入ってる集合を併合
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool findSet(int x, int y) { //xとyが同じ集合に入っているかどうかを判定
		return root(x) == root(y);
	}
	int root(int x) {
		return data[x] < 0 ? x : data[x] = root(data[x]);
	}
	bool isroot(int x) {
		return data[x] < 0;
	}
	int size(int x) {
		return -data[root(x)];
	}
};

int main() {
	int n;
	cin >> n;

	ll dis[301][301] = {}, us[301][301] = {};
	ll ans = 0;
	REP(i, n) {
		REP(j, n) {
			scanf("%lld", &dis[i][j]);
			ans += dis[i][j];
		}
	}
	REP(k, n) {
		REP(i, n) {
			REP(j, n) {
				if (dis[i][j] > dis[i][k] + dis[k][j]) {
					cout << -1 << endl;
					return 0;
				}

				if (i == k || j == k || i == j) continue;
				if (dis[i][j] == dis[i][k] + dis[k][j]) {
					us[i][j] = 1;
				}

			}
		}
	}

	REP(i, n) {
		REP(j, n) {
			if (us[i][j]) ans -= dis[i][j];
		}
	}

	cout << ans/2 << endl;
	return 0;
}