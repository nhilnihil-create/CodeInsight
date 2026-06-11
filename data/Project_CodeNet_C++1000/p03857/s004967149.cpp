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

vector<int> input;

struct uf_tree {
	std::vector<int> parent;
	int __size;
	uf_tree(int size_) : parent(size_, -1), __size(size_) {}
	void unite(int x, int y) {
		if ((x = find(x)) != (y = find(y))) {
			if (parent[y] < parent[x]) std::swap(x, y);
			parent[x] += parent[y];
			parent[y] = x;
			__size--;
		}
	}
	bool is_same(int x, int y) { return find(x) == find(y); }
	int find(int x) { return parent[x] < 0 ? x : parent[x] = find(parent[x]); }
	int size(int x) { return -parent[find(x)]; }
	int size() { return __size; }
};

signed main() {
	int N, K, L;
	cin >> N >> K >> L;
	uf_tree road(1000000), train(1000000);
	for (int i = 0; i < K; i++) {
		int p, q;
		cin >> p >> q;
		road.unite(p, q);
	}
	for (int i = 0; i < L; i++) {
		int r, s;
		cin >> r >> s;
		train.unite(r, s);
	}
	map<pair<int, int>, int> ma;
	//道でも線路でも同じボスに属しているヤツの個数を数える
	for (int i = 1; i <= N; i++) {
		ma[make_pair(road.find(i), train.find(i))]++;
	}
	for (int i = 1; i <= N; i++) {
		cout<< ma[make_pair(road.find(i), train.find(i))];
		if (i == N) break;
		cout << " ";
	}

	return 0;
}