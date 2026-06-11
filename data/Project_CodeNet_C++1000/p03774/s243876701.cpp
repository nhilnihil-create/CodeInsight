#include "bits/stdc++.h"
using namespace std;

int main() {
	int N, M;
	cin >> N >>  M;
	vector<pair<int, int>>A(N);
	vector<pair<int, int>>C(M);
	for (int i = 0;i<N;++i) {
		int x, y;
		cin >> x >> y;
		A[i] = make_pair(x,y);
	}
	for (int i = 0; i < M; ++i) {
		int x, y;
		cin >> x >> y;
		C[i] = make_pair(x, y);
	}
	for (int i = 0;i<N;++i) {
		int ans = -1;
		int dist = 1e9;
		for (int j = 0;j<M;++j) {
			int x = abs(A[i].first - C[j].first) + abs(A[i].second - C[j].second);
			if (dist>x) {
				ans = j;
				dist = x;
			}
		}
		cout <<ans +1 << endl;
	}
	return 0;
}