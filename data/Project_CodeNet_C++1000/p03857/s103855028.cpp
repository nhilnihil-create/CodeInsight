#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

struct Union_Find {
	vector<int> rank, par;
	int independent_tree;
	int N;

	Union_Find(int n) {
		N = n;
		for (int i = 0; i < N; i++)rank.push_back(1), par.push_back(i);
		independent_tree = N;
	}

	int getroot(int X) {
		if (par[X] == X)return X;
		return par[X] = getroot(par[X]);
	}

	bool issame(int A, int B) {
		return getroot(A) == getroot(B);
	}

	void unite(int A, int B) {
		A = getroot(A), B = getroot(B);
		independent_tree--;
		if (A == B)return;
		if (rank[A] > rank[B]) {
			par[B] = A;
		}
		else if (rank[A] == rank[B]) {
			par[B] = A;
			rank[A]++;
		}
		else {
			par[A] = B;
		}
	}

};

int main() {
	int N, K, L;
	cin >> N >> K >> L;
	Union_Find uf1(N), uf2(N);
	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		uf1.unite(a, b);
	}
	for (int i = 0; i < L; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		uf2.unite(a, b);
	}

	map<P, int> Map;
	for (int i = 0; i < N; i++) {
		Map[P(uf1.getroot(i), uf2.getroot(i))]++;
	}
	for (int i = 0; i < N; i++) {
		cout << Map[P(uf1.getroot(i), uf2.getroot(i))] << " ";
	}
	cout << endl;
	return 0;
}