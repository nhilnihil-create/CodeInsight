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
#include <numeric>
#include <bitset>
#include <limits>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<LL, LL> PP;
#define REP(i,a,n) for(int i = (a); i < (int)(n); ++i)
#define REPM(i,n,a) for(int i = ((n) - 1); i >= (a); --i)
#define FLOAT setprecision(16)
const int INF = 0x3FFFFFFF;
const LL INFLL = 0x3FFFFFFF3FFFFFFF;
const double INFD = 1.0e+308;
const double EPS = 1.0e-9;

template <class T, class U>
istream& operator>>(istream& ist, pair<T, U>& right) { return ist >> right.first >> right.second; }
template <class T, class U>
ostream& operator<<(ostream& ost, pair<T, U>& right) { return ost << right.first << ' ' << right.second; }
template <class T, class TCompatible, size_t N>
void Fill(T(&dest)[N], const TCompatible& val) { fill(begin(dest), end(dest), val); }
template <class T, class TCompatible, size_t M, size_t N>
void Fill(T(&dest)[M][N], const TCompatible& val) { for (int i = 0; i < M; ++i) Fill(dest[i], val); }
// all_of

#if 1234567891
#include <array>
#include <unordered_set>
#include <unordered_map>
template<typename T>
using PriorityQ = priority_queue<T, vector<T>, greater<T> >;	// コスト小を優先
#endif

#if _DEBUG
#include "IntMod.h"
#include "Union_Find.h"
#include "Graph.h"
#endif

int H, W, D;
string s[500];
void ki() {
	REP(i, 0, H) {
		REP(j, 0, W) {
			if (i % 2 == j % 2) {
				s[i][j] = 'R';
			} else {
				s[i][j] = 'Y';
			}
		}
	}
}
void kigu() {
	REP(i, 0, H) {
		REP(j, 0, W) {
			s[i][j] = "RYGB"[(i % 4 + ((j / 2) % 2) * 2) % 4];
		}
	}
}
void gu() {
	REP(i, 0, H) {
		REP(j, 0, W) {
			bool b = i / D % 2 == j / D % 2;
			int p = b ? i % D : (D - 1 - i % D);
			int q = j % D;
			int r = 4;
			if (p <= q && p < D - q - 1)r = 0;
			if (p > q && p <= D - q - 1)r = 1;
			if (p < q && p >= D - q - 1)r = 2;
			if (p >= q && p > D - q - 1)r = 3;
			s[i][j] = b ? "RYGB."[r] : "RGYB."[r];
		}
	}
}

int main() {
	cin >> H >> W >> D;
	REP(i, 0, H) {
		s[i].resize(W);
	}
	if (D % 2 == 1) {
		ki();
	} else {
		if (D % 4 == 2) {
			kigu();
		} else {
			gu();
		}
	}


	REP(i, 0, H) {
		cout << s[i] << endl;
	}
	return 0;
}

