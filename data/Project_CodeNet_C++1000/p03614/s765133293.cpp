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
#include <nmmintrin.h>
#include <chrono>
const double EPS = 1e-8;
#define Scan(a) int a;scanf("%d", &a);
#define ScanS(a) char a[500];scanf("%s", a);
#define rep(i,s,n) for(int i = (s); (n) > i; i++)
#define REP(i,n) rep(i,0,n)
#define RANGE(x,a,b) ((a) <= (x) && (x) <= (b))
#define DUPLE(a,b,c,d) (RANGE(a,c,d) || RANGE(b,c,d) || RANGE(c,a,b) || RANGE(d,a,b))
#define INCLU(a,b,c,d) (RANGE(a,c,d) && (b,c,d))
#define PW(x) ((x)*(x))
#define ALL(x) (x).begin(), (x).end()
#define MODU 1000000007
#define bitcheck(a,b)   ((a >> b) & 1LL)
#define bitset(a,b)      ( a |= (1LL << b))
#define bitunset(a,b)    (a &= ~(1LL << b))
#define MP(a,b) make_pair((a),(b))
#define Manh(a,b) (abs((a).first-(b).first) + abs((a).second - ((b).second))
#define pritnf printf
#define scnaf scanf
#define itn int
#ifdef _MSC_VER
#define __builtin_popcount _mm_popcnt_u32
#define __builtin_popcountll _mm_popcnt_u64
#endif
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T &val) {
	std::fill((T*)array, (T*)(array + N), val);
}

pii Dir[8] = {
	{ 0 ,1 },{ -1 ,0 },{ 1 ,0 },{ 0 ,-1 },
	{ 1 ,1 },{ 1 ,-1 },{ -1 ,1 },{ -1 ,-1 }
};


pii operator+(pii obj, pii obj2) {
	return MP(obj.first + obj2.first, obj.second + obj2.second);
}
pii operator-(pii obj, pii obj2) {
	return MP(obj.first - obj2.first, obj.second - obj2.second);
}

struct Edge {
	int from, to, weight;
};

typedef vector<vector<Edge>> Graph;
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
	int ans = 0;
	bool bef = 0;
	REP(i, n) {
		int a;
		scanf("%d", &a);
		if (!bef && a == i + 1) {
			ans++;
			bef = true;
		}
		else
			bef = false;
	}

	cout << ans << endl;
	return 0;
}