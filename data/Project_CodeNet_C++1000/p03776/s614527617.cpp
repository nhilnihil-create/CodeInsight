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


LL nCk(LL N, LL k) {
	LL ans = 1;
	for (int i = 1; i <= k; ++i) {
		ans *= (N - i+1);
		ans /= i;
	}

	return ans;
}

void solve() {
	int N, A, B;
	cin >> N >> A >> B;
	vector<LL> V(N);
	for (int i = 0; i < N; ++i) {
		cin >> V[i];
	}
	sort(V.begin(), V.end());
	LD sum = 0;
	for (int i = N-1; i>=N-1-A+1 ; --i) {
		sum += V[i];
	}

	//
	LL ans = 0;
	if (V[N - 1] == V[N - A]) {
		int index = lower_bound(V.begin(), V.end(), V[N - 1]) - V.begin();
		for (int i = A; i <= min(N - index,B); ++i) {
			ans += nCk(N - index, i);
		}
	}
	else {

		int indexL = lower_bound(V.begin(), V.end(), V[N - A]) - V.begin();
		int indexR = lower_bound(V.begin(), V.end(), V[N - A]+1) - V.begin();
		int CC = indexR - indexL;//取る元集団。
		int toru = indexR - (N - A);
		ans = nCk(CC, toru);
	}

	cout << sum / A << endl;
	cout << ans << endl;
}

signed main(void) {
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	std::cout << std::fixed;//小数を10進数表示
	cout << setprecision(16);//小数点以下の桁数を指定//coutとcerrで別	

	solve();
}
