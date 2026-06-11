#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
int N, M;
vector<vector<int>> G;
vector<int> color;
bool f(int p, int q, int c) {
	bool r = true;
	color[p] = c;
	for (int x : G[p]) if (x != q) {
		if (color[x] == 0) {
			if (!f(x, p, 3 - c)) r = false;
		} else {
			if (color[x] == color[p]) r = false;
		}
	}
	return r;
}
int main() {
	cin >> N >> M;
	G.resize(N);
	for (int i = 0; i < M; ++i) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	long long x = 0, y = 0, z = 0;
	color.resize(N);
	for (int i = 0; i < N; ++i) {
		if (G[i].size() == 0) {
			++x;
		} else if (color[i] == 0) {
			if (f(i, -1, 1)) {
				++z;
			} else {
				++y;
			}
		}
	}
	long long r = 0;
	r += 2 * x * N - x * x;
	r += 2 * y * z + y * y;
	r += 2 * z * z;
	cout << r << endl;
}

// 連結な単純無向グラフAと連結な単純無向グラフBが与えられたとして
// 問題の規則によってC = A×Bを作り、その連結成分数を考える。
// 「Cで(a, b)と(a', b')が連結であること」と、「Aでaからa'に、Bでbからb'に同じ長さのパスが存在すること」は同値
// また、A,Bいずれも 頂点数 >= 2のとき、パスの長さは2伸ばすことができるので、「同じ長さのパスが存在する」は「偶奇が等しいパスが存在する」と言い換えられる
// - どちらかが頂点数 = 1のとき、連結成分の個数は |A| * |B| (*1)
// - 両方が頂点数 >= 2のとき
//   - どちらかが二部グラフでないとき : 連結成分の個数は 1 (*2)
//   - 両方が二部グラフであるとき : 連結成分の個数は 2 (*3)
// 各連結成分について上記を考える
// x = (頂点数 = 1)の数, y = (二部グラフでない)の数, z = (二部グラフである)の数
// (*1)の総和 = 2 * x * N - x * x
// (*2)の総和 = 2 * y * z + y * y
// (*3)の総和 = 2 * z * z
