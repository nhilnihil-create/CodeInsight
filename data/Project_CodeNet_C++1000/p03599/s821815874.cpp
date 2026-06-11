#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <stdio.h>

#include <sstream>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <complex>

#include <string>
#include <cstring>
#include <vector>
#include <bitset>

#include <queue>
#include <set>
#include <map>
#include <stack>
#include <list>

#include <ctime>
////
//#include <random>//
/////////

typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;

////定数
const int INF = (int)1e9 + 10;
const LL MOD = (LL)1e9 + 7;
const LL LINF = (LL)4e18 + 20;
const LD PI = acos(-1.0);
const double EPS = 1e-9; 
/////////
using namespace::std;
template<typename T>
void chmax(T& a, T b) {
	a = max(a, b);
}

template<typename T>
void chmin(T& a, T b) {
	a = min(a, b);
}

template<typename T>
void IN(vector<T> &A,int N=-1) {
	if (N == -1) {
		N = A.size();
	}
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
}

template<typename T>
void SO(vector<T> &A,bool F=false) {
	sort(A.begin(), A.end());
	if (F) {
		reverse(A.begin(), A.end());
	}
}
//////////////


void solve() {
	int A, B, C, D, E, F;
	cin >> A >> B >> C >> D >> E >> F;
	vector<vector<int> >dp(F + 1, vector<int>(F + 1, 0));
	dp[0][0] = 1;
	for (int f = 0; f < F; ++f) {
		for (int mizu = 0; mizu < f; mizu+=100) {
			for (int syu = 0; mizu + syu < f; ++syu) {
				if (dp[mizu][syu] == 0) continue;
				if (mizu + 100 * A <= F) {
					dp[mizu + 100 * A][syu] = 1;
				}
				if (mizu + 100 * B <= F) {
					dp[mizu + 100 * B][syu] = 1;
				}
				if (syu + C <= F) {
					dp[mizu][syu + C] = 1;
				}
				if (syu + D <= F) {
					dp[mizu][syu + D] = 1;
				}
			}
		}
	}

	int ansmizu = 100*A;
	int anssyu = 0;
	LD ansNo = 0;
	for (int f = 0; f <= F; ++f) {
		for (int mizu = 0; mizu <= f; mizu+=100) {
			for (int syu = f-mizu; syu>=0; --syu) {
				if (dp[mizu][syu] == 0) continue;
				if (E * mizu / 100 < syu) continue;//溶けてない
				
				

				LD M = mizu;
				LD S = syu;
				LD res = 100 * S / (M + S);
				if (anssyu*(mizu+syu) < (anssyu+ansmizu)*syu) {
					ansmizu = M;
					anssyu = S;
					ansNo = res;
				}
				break;
			}
		}
	}
	cout <<ansmizu+ anssyu << " " << anssyu << endl;
}

signed main(void) {
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	std::cout << std::fixed;//小数を10進数表示
	cout << setprecision(16);//小数点以下の桁数を指定//coutとcerrで別	

	solve();
}
