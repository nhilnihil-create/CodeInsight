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
#define R(i,n) for(int i=0;i<(n);i=i+1)
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
struct edge {
	int to; LL cost;
};
vector<vector<edge>>G(200);
void solve() {
	int N, M, R;
	cin >> N >> M >> R;
	vector<int> path(R);
	for (int i = 0; i < R; ++i) {
		cin >> path[i];
		path[i]--;
	}
	vector<vector<LL>>dist(N, vector<LL>(N, LINF) );
	R(i, N)dist[i][i] = 0;
	R(i, M) {
		int a, b, c;
		cin >> a >> b >> c; --a; --b;
		dist[a][b] = c;
		dist[b][a] = c;
	}
	
	R(k, N)R(i, N)R(j, N)chmin(dist[i][j], dist[i][k]+ dist[k][j]);
	
	SO(path);
	LL ans = LINF;
	do {
		LL res = 0;
		for (int i = 0; i < R - 1; ++i) {
			res += dist[path[i]][path[i + 1]];
		}
		chmin(ans, res);
	} while (next_permutation(path.begin(), path.end()));
	cout << ans << endl;
}

signed main(void) {
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	std::cout << std::fixed;//小数を10進数表示
	cout << setprecision(16);//小数点以下の桁数を指定//coutとcerrで別	

	solve();
}