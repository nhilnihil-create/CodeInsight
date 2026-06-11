#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<stack>
#include<map>
using namespace std;

#define int long long
using namespace std;

class UF {
public:
	vector<int> rank;
	vector<int> p;

	UF() {}
	UF(int size) {
		rank.resize(size, 0);
		p.resize(size, 0);
		for (int i = 0;i < size;i++) makeSet(i);
	}
	
	void makeSet(int x) {
		p[x] = x;
		rank[x] = 0;
	}
	
	bool same(int x, int y) {
		return findSet(x) == findSet(y);
	}

	void unite(int x, int y) {
		link(findSet(x), findSet(y));
	}

	void link(int x, int y) {
		if (rank[x] > rank[y]) {
			p[y] = x;
		}
		else {
			p[x] = y;
			if (rank[x] == rank[y]) {
				rank[y]++;
			}
		}
	}

	int findSet(int x) {
		if (x != p[x]) {
			p[x] = findSet(p[x]);
		}
		return p[x];
	}
};


signed main() {
	int N, K, L;
	cin >> N >> K >> L;
	UF load(N), train(N);

	for (int i = 0;i < K;i++) {
		int p, q;
		cin >> p >> q;
		p--; q--;//0-indexed
		load.unite(p, q);
	}

	for (int i = 0;i < L;i++) {
		int r, s;
		cin >> r >> s;
		r--; s--;
		train.unite(r, s);
	}
	
	map<pair<int,int>, int> mp;
	for (int i = 0;i < N;i++) {
		mp[pair<int, int>(load.findSet(i), train.findSet(i))]++;
	}


	for (int i = 0;i < N;i++) {
		cout << mp[pair<int, int>(load.findSet(i), train.findSet(i))] << endl;
	}
}