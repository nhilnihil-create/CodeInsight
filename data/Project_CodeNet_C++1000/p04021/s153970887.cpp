#ifndef __COMPRESSOR_H__
#define __COMPRESSOR_H__

/* updated: 2020-02-13 */

#include <cstdint>
#include <vector>
#include <map>

/* 座標圧縮を行うクラス */
/* クラス T は比較可能である必要がある */
/* add(要素追加) -> execute(対応づけ) -> get(ID取得) という流れ */
template <class T>
class Compressor {
	using Dict = std::map<T, int32_t>;
	Dict dict_m;

public:
	void add(const T& object);
	void execute();
	int32_t get(const T& object) const;
};

/* 要素を登録する O(log n) */
template <class T>
void Compressor<T>::add(const T& object) {
	dict_m.emplace(object, int32_t());
}

/* 各要素に座標圧縮後の ID を対応づける O(n) */
template <class T>
void Compressor<T>::execute() {
	int32_t current = int32_t();
	for (auto&& pair : dict_m) {
		pair.second = current;
		++current;
	}
}

/* 各要素に対応付けられた ID を得る O(log n) */
/* 存在しない場合は例外を投げる */
template <class T>
int32_t Compressor<T>::get(const T& object) const {
	return dict_m.at(object);
}

template <class T>
std::vector<int32_t> compress(const std::vector<T>& arr);

/* 配列の各要素を座標圧縮した結果を返す O(n log n) */
template <class T>
std::vector<int32_t> compress(const std::vector<T>& arr) {
	/* 要素を全て登録 */
	Compressor<T> compressor;
	for (const T& object : arr) {
		compressor.add(object);
	}
	compressor.execute();
	
	/* 各要素に対応づけられた ID を得る */
	std::vector<int32_t> ret;
	ret.reserve(arr.size());
	for (const T& object : arr) {
		int32_t id = compressor.get(object);
		ret.push_back(id);
	}
	return ret;
}

#endif

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

int N;
int main() {
	cin >> N;
	vector<int> v;
	REP(i, 0, N) v.push_back(Next<int>());
	auto w = compress(v);

	int cnt = 0;
	REP(i, 0, N) {
		if (i % 2 != 0) continue;
		if (w[i] % 2 != 0) ++cnt;
	}
	cout << cnt << endl;
	return 0;
}

