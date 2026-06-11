#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class UnionFind {
	vector<int> data;
	vector<int> rank;
	int root(int a) {
		return data[a] < 0 ? a : data[a] = root(data[a]);
	}
public:
	UnionFind(int n) : data(n, -1), rank(n, 1) {}
	bool Find(int a, int b) {
		return root(a) == root(b);
	}
	void Union(int a, int b) {
		a = root(a);
		b = root(b);
		if (a == b) return;
		if (rank[a] < rank[b]) {
			data[a] += data[b];
			data[b] = a;
		}
		else {
			data[b] += data[a];
			data[a] = b;
			if (rank[a] == rank[b]) rank[b]++;
		}
	}
	int Size(int a) {
		return -data[root(a)];
	}
	int Rank(int a) {
		return rank[root(a)];
	}
};

int main()
{
	ll N, M;
	cin >> N >> M;
	UnionFind uf(N * 2), uf2(N + 1);
	for (int i = 0, u, v; i < M; i++) {
		cin >> u >> v; u--; v--;
		uf.Union(u, v + N);
		uf.Union(u + N, v);
		uf2.Union(u, v);
	}
	ll res = 0, c1 = 0, c2 = 0, c3 = 0;
	for (int i = 0; i < N; i++) {
		if (!uf2.Find(i, N)) {
			if (uf2.Size(i) == 1) {
				c1++;
			}
			else if (!uf.Find(i, i + N)) {
				c2++;
			}
			else {
				c3++;
			}
			uf2.Union(i, N);
		}
	}
	res = N * c1 * 2 - c1 * c1 + c2 * c2 * 2 + c2 * c3 * 2 + c3 * c3;
	cout << res << endl;
	return 0;
}
