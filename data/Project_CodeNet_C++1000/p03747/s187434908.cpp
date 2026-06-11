#define _CRT_SECURE_NO_WARNINGS
#define _SCL_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
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

using namespace std;
typedef unsigned int uint;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<LL, LL> PP;
#define REP(i,a,n) for(LL i = (a); i < (LL)(n); ++i)
#define REM(i,a,n) for(LL i = ((n) - 1); i >= (a); --i)
#define FLOAT fixed << setprecision(16)
#define SPEEDUP {cin.tie(0); ios::sync_with_stdio(false);}
const int INF = 0x3FFFFFFF;
const LL INFLL = 0x3FFFFFFF3FFFFFFF;
const double INFD = 1.0e+308;
const string INFSTR = "\x7f";
const double EPS = 1.0e-9;

void YesNo(bool b) { cout << (b ? "Yes" : "No") << endl; }
void YESNO(bool b) { cout << (b ? "YES" : "NO") << endl; }
template <class T, class U>
istream& operator>>(istream& ist, pair<T, U>& right) { return ist >> right.first >> right.second; }
template <class T, class U>
ostream& operator<<(ostream& ost, const pair<T, U>& right) { return ost << right.first << ' ' << right.second; }
template <class T, class TCompatible, size_t N>
void Fill(T(&dest)[N], const TCompatible& val) { fill(dest, dest + N, val); }
template <class T, class TCompatible, size_t M, size_t N>
void Fill(T(&dest)[M][N], const TCompatible& val) { for (int i = 0; i < M; ++i) Fill(dest[i], val); }
template<class T>
T Compare(T left, T right) { return left > right ? 1 : (left < right ? -1 : 0); }
istream& Ignore(istream& ist) { string s; ist >> s; return ist; }
bool Inside(int i, int j, int h, int w) { return i >= 0 && i < h && j >= 0 && j < w; }
// all_of
// partial_sum, adjacent_difference

#ifdef ONLY_MY_ENVIR
#include "IntMod.h"
#include "Union_Find.h"
#include "Graph.h"
#include "Range.h"
#include "Global.h"
#include "Flow_Solver.h"
#include "Tree.h"
#include "Suffix_Array.h"
#include "Geometry.h"
#include "Matrix.h"
#endif

#ifdef __GNUC__
typedef __int128 LLL;
istream& operator>> (istream& ist, __int128& val) { LL tmp;  ist >> tmp; val = tmp; return ist; }
ostream& operator<< (ostream& ost, __int128 val) { LL tmp = val; ost << tmp; return ost; }
#endif

#if 1234567891
#include <array>
#include <random>
#include <unordered_set>
#include <unordered_map>
template<typename T>
using PriorityQ = priority_queue<T, vector<T>, greater<T> >;	// コスト小を優先
#endif

LL N, L, T;
LL X[100000], Y[100000];
int sgn[100000];

int main() {
	cin >> N >> L >> T;
	REP(i, 0, N) {
		int a;
		cin >> X[i] >> a;
		sgn[i] = (a == 1 ? 1 : -1);
	}

	REP(i, 0, N) {
		Y[i] = X[i] + sgn[i] * T;
	}
	
	LL cross = 0;
	const LL BIG = 2e9;
	REP(i, 0, N) {
		cross += (Y[i] - Y[0] + L * BIG) / L - (X[i] - X[0] + L * BIG) / L;
	}

	LL reference = Y[0];
	REP(i, 0, N) {
		Y[i] = (Y[i] + L * BIG - reference) % L;
	}
	sort(Y, Y + N);
	REP(i, 0, N) {
		Y[i] = (Y[i] + L * BIG + reference) % L;
	}

	REP(i, 0, N) {
		cout << Y[(i + cross + N * BIG) % N] << endl;
	}

	return 0;
}