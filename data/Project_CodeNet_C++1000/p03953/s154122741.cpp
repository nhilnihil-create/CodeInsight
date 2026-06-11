#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>

using namespace std;
typedef long long ll;

/////////////         UnionFind
//    バラバラの要素を結合してグループにまとめる際に使える構造。
//    グループ番号、要素数の取得が可能だが、グループに属する要素の列挙はO(N)かかる。

class unionFindClass {
public:
	unionFindClass() {
		N = 0;
		parent = NULL;
		size = NULL;
	}
	~unionFindClass() {
		if (parent != NULL) {
			delete[] parent;
		}
		if (size != NULL) {
			delete[] size;
		}
	}

	void activate(int n) {// 要素の数N
		N = n;
		parent = new int[N];
		size = new int[N];
		for (int i = 0; i < N; i++) {
			parent[i] = -1;
			size[i] = 1;
		}
	}

	int getParent(int x) {// グループの親の番号を得る
		if (parent[x] == -1) {
			return x;
		}
		else {
			int y = getParent(parent[x]);
			parent[x] = y;
			return y;
		}
	}
	int getSize(int x) {// 自分が属するグループのサイズを得る
		x = getParent(x);
		return size[x];
	}
	bool connect(int x, int y) {// 二つの要素を結ぶ。２グループ間を繋いだ場合trueを返す
		x = getParent(x);
		y = getParent(y);
		if (x == y) { return false; }
		int xsize = getSize(x), ysize = getSize(y);
		if (xsize < ysize) {
			parent[x] = y;
			size[y] += size[x];
			size[x] = 0;
		}
		else {
			parent[y] = x;
			size[x] += size[y];
			size[y] = 0;
		}
		return true;
	}

	//データ
	int N;// 個数
	int* parent;// 親の番号。自分自身が親なら-1。
	int* size;// 親のみ有効。自分のグループのサイズ。
};

void swap(ll* x, ll* y) {
	ll c = *y;
	*y = *x;
	*x = c;
}

int main() {
	ll N, M, K; cin >> N;

	ll* a = new ll[N];
	ll* b = new ll[N - 1];
	ll* c = new ll[N - 1];
	bool* flag = new bool[N - 1];

	for (int i = 0; i < N; i++) {
		cin >> a[i];
		if (i != N - 1) {
			b[i] = i;
			c[i] = 0;
			flag[i] = false;
		}
	}

	cin >> M >> K;

	for (int i = 0; i < M; i++) {
		int k; cin >> k;
		swap(&b[k - 2], &b[k - 1]);
	}
	
	unionFindClass uf;
	uf.activate(N - 1);

	for (int i = 0; i < N - 1; i++) {
		if (flag[i] == false) {
			int k = i;
			while (flag[k] == false) {
				flag[k] = true;
				uf.connect(k, b[k]);
				k = b[k];
			}
		}
	}

	for (int i = 0; i < N - 1; i++) {
		flag[i] = false;
	}
	for (int i = 0; i < N - 1; i++) {
		if (flag[i] == false) {
			ll size = uf.getSize(i);
			ll r = K % size;
			int p = i;
			int q = p;
			for (int j = 0; j < r; j++) {
				q = b[q];
			}
			for (int j = 0; j < size; j++) {
				flag[p] = true;
				c[p] = q;
				p = b[p];
				q = b[q];
			}
		}
	}
	for (int i = 0; i < N - 1; i++) {
		b[i] = a[i + 1] - a[i];
	}

	ll buf = 0;
	for (int i = 0; i < N; i++) {
		if (i == 0) { buf = a[0]; }
		else {
			buf += b[c[i - 1]];
		}
		cout << buf << endl;
	}

	return 0;
}