#include<iostream>
#include<vector>
#include<string>

using namespace std;

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
	int N;
	string s;
	cin >> N >> s;

	bool narabi[100000];//true == Sheep  false == Wolf
	for (int bit = 0; bit < 4; bit++) {
		if (bit % 2 == 0)narabi[1] = true;
		else narabi[1] = false;

		if (bit & 2)narabi[0] = false;
		else narabi[0] = true;

		for (int i = 1; i < N - 1; i++) {
			if (s[i] == 'o') {
				if (narabi[i])narabi[i + 1] = narabi[i - 1];
				else narabi[i + 1] = !narabi[i - 1];
			}
			else {
				if (narabi[i])narabi[i + 1] = !narabi[i - 1];
				else narabi[i + 1] = narabi[i - 1];
			}
		}
		bool f = false;
		if ((s[N - 1] == 'o' && (narabi[N - 1] ^ (narabi[N - 2] != narabi[0]))) ^ 
			(s[N - 1] == 'x' && (narabi[N - 1] ^ (narabi[N - 2] == narabi[0])))) {
			if (s[0] == 'o' && (narabi[0] ^ (narabi[N - 1] != narabi[1])))f = true;
			if (s[0] == 'x' && (narabi[0] ^ (narabi[N - 1] == narabi[1])))f = true;
		}
		
		if (f) {
			for (int i = 0; i < N; i++) {
				if (narabi[i])cout << "S";
				else cout << "W";
			}
			cout << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}