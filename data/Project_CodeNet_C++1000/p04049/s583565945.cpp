#define _CRT_SECURE_NO_WARNINGS
#define _SCL_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <utility>
#include <algorithm>
#include <functional>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <limits>
#include <numeric>
#include <valarray>
#include <fstream>
#include <array>
#include <random>
#include <unordered_set>
#include <unordered_map>

using namespace std;
using uint = uint32_t;
using LL = int64_t;
using ULL = uint64_t;
using PP = pair<LL, LL>;
template <typename T> using PriorityQ = priority_queue<T, vector<T>, greater<T> >;
#define REP(i, a, n) for(LL i = (a), i##_max_ = (n); i < i##_max_; ++i)
#define REM(i, a, n) for(LL i = (LL)(n) - 1, i##_min_ = (a); i >= i##_min_; --i)
#define FLOAT fixed << setprecision(16)
#define SPEEDUP { cin.tie(NULL); ios::sync_with_stdio(false); }
const int INF = 0x3FFFFFFF;
const LL INFLL = 0x3FFFFFFF3FFFFFFF;
const double INFD = 1.0e+308;
const double EPS = 1.0e-9;

void YesNo(bool b) { cout << (b ? "Yes" : "No") << endl; }
void YESNO(bool b) { cout << (b ? "YES" : "NO") << endl; }
template <class T, class U> istream& operator>>(istream& ist, pair<T, U>& right) { return ist >> right.first >> right.second; }
template <class T, class U> ostream& operator<<(ostream& ost, const pair<T, U>& right) { return ost << right.first << ' ' << right.second; }
template <class T, class TCompatible, size_t N> void Fill(T(&dest)[N], const TCompatible& val) { fill(dest, dest + N, val); }
template <class T, class TCompatible, size_t M, size_t N> void Fill(T(&dest)[M][N], const TCompatible& val) { for (int i = 0; i < M; ++i) Fill(dest[i], val); }
template <class T> T Next() { T buf; cin >> buf; return buf; }
istream& Ignore(istream& ist) { string s; ist >> s; return ist; }
bool Inside(int i, int j, int h, int w) { return i >= 0 && i < h && j >= 0 && j < w; }

#ifdef ONLY_MY_ENVIR
#include "Accumulator.h"
#include "Algebraic.h"
#include "BinaryMatrix.h"
#include "BinaryTree.h"
#include "Bipartite.h"
#include "BIT.h"
#include "Compressor.h"
#include "Decompositions.h"
#include "DiscreteLog.h"
#include "DynamicMod.h"
#include "Exponential.h"
#include "Factorization.h"
#include "FFT.h"
#include "FlowSolver.h"
#include "Graph.h"
#include "GraphUtil.h"
#include "IntMod.h"
#include "LazySegmentTree.h"
#include "LIS.h"
#include "Math.h"
#include "MathUtil.h"
#include "Matrix.h"
#include "MinCostFlowSolver.h"
#include "MinMax.h"
#include "Numbers.h"
#include "Optimize.h"
#include "Permutation.h"
#include "Polynomial.h"
#include "Position.h"
#include "Random.h"
#include "Range.h"
#include "Rational.h"
#include "RuntimeMod.h"
#include "SegmentTree.h"
#include "SegmentTree2D.h"
#include "Sets.h"
#include "Shortest.h"
#include "SlidingWindow.h"
#include "SpanningTree.h"
#include "StringSearching.h"
#include "SuffixArray.h"
#include "SwitchList.h"
#include "Timer.h"
#include "Tree.h"
#include "TreeUtil.h"
#include "UnionFind.h"
#include "Util.h"
#include "VectorUtil.h"
#endif

#ifdef __GNUC__
typedef __int128 LLL;
istream& operator>>(istream& ist, __int128& val) { LL tmp; ist >> tmp; val = tmp; return ist; }
ostream& operator<<(ostream& ost, __int128 val) { LL tmp = val; ost << tmp; return ost; }
#endif


int N, K;
vector<int> G[4000];

int rec(int from, int prev, int dist) {
	if (dist > K) return 0;
	int sum = 1;
	for (int to : G[from]) {
		if (to == prev) continue;
		sum += rec(to, from, dist + 1);
	}
	return sum;
}

int sub(int st) {
	int res = rec(st, -1, 0);
	return 2 * (N - 1) - (res - 1);
}

int main() {
	cin >> N >> K;
	REP(i, 0, N - 1) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		int c = N + i;
		G[a].push_back(c);
		G[c].push_back(a);
		G[b].push_back(c);
		G[c].push_back(b);
	}
	
	int mn = INF;
	if (K % 2 == 0) {
		REP(i, 0, N) {
			mn = min(mn, sub(i));
		}
	} else {
		REP(i, N, 2 * N - 1) {
			mn = min(mn, sub(i));
		}
	}

	cout << mn / 2 << endl;
	return 0;
}
