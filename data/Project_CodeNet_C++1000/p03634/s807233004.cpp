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
//////////////
int N;
vector<vector<pair<int,int>>>G;
vector<int> depth;
int root = 0;
vector<bool> use;
vector<vector<LL>>dist;
vector<vector<int>>oya;
void set_dat(int R,int x,int d,LL D) {
	oya[x][0] = R;
	use[x] = true;
	depth[x] = d;
	dist[x][0] = D;
	
	for (int i = 0; i < G[x].size(); ++i) {
		int ter = G[x][i].first;
		if (use[ter])continue;
		set_dat(x,ter, d + 1,dist[x][0]+G[x][i].second);
	}
}
void solve() {
	cin >> N;
	G = vector<vector<pair<int,int>>>(N);
	depth = vector<int>(N,0);
	use = vector<bool>(N, false);
	dist = vector<vector<LL>>(N, vector<LL>(20));
	oya = vector<vector<int>>(N, vector<int>(20));
	pair<int, int> edge;
	for (int i = 0; i < N-1; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		--a; --b;
		edge.first = b;
		edge.second = c;
		G[a].push_back(edge);
		edge.first = a;
		G[b].push_back(edge);
	}
	int Q, K;
	cin >> Q >> K;
	--K;
	root = K;
	set_dat(-1,root,0,0);
	/*
	for (int k = 0; k < 19; ++k) {
		for (int i = 0; i < N; ++i) {
			int A;
			A = oya[i][k];
			if (A == -1)continue;
			oya[i][k + 1] = oya[A][k];
		}
	}*/
	int x, y;
	for (int i = 0; i < Q; ++i) {
		cin >> x >> y;
		--x; --y;
		LL res = dist[x][0] + dist[y][0];
		cout << res << endl;
	}
}

signed main(void) {
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	std::cout << std::fixed;//小数を10進数表示
	cout << setprecision(16);//小数点以下の桁数を指定//coutとcerrで別	

	solve();
}
