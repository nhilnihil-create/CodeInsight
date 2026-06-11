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
void chmax(LL& a, LL b) {
	a = max(a, b);
}
void chmin(LL& a, LL b) {
	a = min(a, b);
}
//////////////

void solve() {
	int H, W, N;
	cin >> H >> W >> N;
	vector<int>A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector < vector<int>> C(H, vector<int>(W));
	int index = 0;
	for (int h = 0; h < H; ++h) {
		for (int w = 0; w <W; ++w) {
			if (h & 1) {
				C[h][W-w-1] = index + 1;
			}
			else {
				C[h][w] = index + 1;
			}
			A[index]--;
			if (A[index] == 0) {
				index++;
			}
		}
	}
	for (int h = 0; h < H; ++h) {
		for (int w = 0; w < W; ++w) {
			if (w)cout << " ";
			cout << C[h][w];
		}
		cout << endl;
	}
}

signed main(void) {
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	std::cout << std::fixed;//小数を10進数表示
	cout << setprecision(16);//小数点以下の桁数を指定//coutとcerrで別	

	solve();
}
