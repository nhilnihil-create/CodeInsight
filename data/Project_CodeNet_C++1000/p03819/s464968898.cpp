#include "bits/stdc++.h"
using namespace std;

class BIT {
private:
	long long Size;
	vector<long long> Node;
public:
	BIT(long long N) : Size(N) {
		Node.resize(Size + 1, 0);
	}
	void Update(long long N, long long X) {
		for (long long i = N; i <= Size; i += (i & -i)) {
			Node[i] += X;
		}
	}
	long long Query(long long N) {
		if (N == 0) return 0;
		long long ANS = 0;
		for (long long i = N; i > 0; i -= (i & -i)) {
			ANS += Node[i];
		}
		return ANS;
	}
};

int main() {
	long long N, M;
	cin >> N >> M;
	vector<vector<long long> > V(M + 1);
	for (int i = 0; i < N; i++) {
		long long S, T;
		cin >> S >> T;
		V[S].push_back(T);
	}
	vector<vector<long long> > D(M + 1);
	vector<long long> ANS(M + 1, 0);
	BIT B(M);
	for (int i = 1; i <= M; i++) {
		for (int j = 0; i * j <= M; j++) {
			D[i * j].push_back(i);
		}
	}
	for (int i = M; i > 0; i--) {
		for (int j = 0; j < V[i].size(); j++) B.Update(V[i][j], 1);
		for (long long X : D[i - 1]) {
			long long NX = min(M, i + X - 2);
			ANS[X] += B.Query(NX);
		}
	}
	for (int i = 1; i <= M; i++) cout << N - ANS[i] << endl;
}