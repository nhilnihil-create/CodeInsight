#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <numeric>
#include <queue>
#include <map> 
#include <set>
#include <string>
#include <functional>
#include <list>
#include <random>
#include <time.h>
#include <iomanip>
#include <assert.h>
#define int long long
#define double long double
#define oku7 1000000007
#define MAXN (int)1e+5 * 2+1
#define LL_MAX 9223372036854775807	//ない環境用
#define LL_HALFMAX 9223372036854775807 / 2	//ない環境用

using namespace std;
std::mt19937 mt((int)time(0));

int dx[4] = { 0, 1, 0, -1 }; // x軸方向への変位
int dy[4] = { 1, 0, -1, 0 }; // y軸方向への変位
vector<int> G[1000000];
int black[100001], white[100001];


signed main() {
	int N;
	cin >> N;
	for (int i = 0; i < N-1; i++) {
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	//白黒を始点にBFSをする
	queue<int> q,r;
	//黒
	black[1] = 1;
	q.push(1);
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (int i : G[node]) {
			if (black[i] != 0) continue;
			black[i] = black[node] + 1;
			q.push(i);
		}
	}
	white[N] = 1;
	r.push(N);
	while(!r.empty()){
		int node = r.front();
		r.pop();
		for (int i : G[node]) {
			if (white[i] != 0) continue;
			white[i] = white[node] + 1;
			r.push(i);
		}
	}

	int fennec = 0, snuke = 0;
	for (int i = 1; i <= N; i++) {
		if (black[i] <= white[i]) {
			fennec++;
		}
		else {
			snuke++;
		}
	}
	if (fennec > snuke) cout << "Fennec\n";
	else cout << "Snuke\n";
	


	return 0;
}