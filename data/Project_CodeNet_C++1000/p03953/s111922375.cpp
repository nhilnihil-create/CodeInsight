#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N, M; long long K;
	cin >> N;
	vector<int> X(N);
	for (int i = 0; i < N; ++i) cin >> X[i];
	cin >> M >> K;
	vector<int> perm(N - 1);
	for (int i = 0; i < N - 1; ++i) perm[i] = i;
	for (int i = 0; i < M; ++i) {
		int A;
		cin >> A;
		swap(perm[A - 2], perm[A - 1]);
	}
	vector<int> p(N - 1);
	for (int i = 0; i < N - 1; ++i) p[i] = i;
	for (int i = 0; i < 60; ++i) {
		if ((K >> i) & 1) {
			vector<int> nxtp(N - 1);
			for (int j = 0; j < N - 1; ++j) {
				nxtp[j] = p[perm[j]];
			}
			p = nxtp;
		}
		vector<int> nxtperm(N - 1);
		for (int j = 0; j < N - 1; ++j) {
			nxtperm[j] = perm[perm[j]];
		}
		perm = nxtperm;
	}
	long long ans = X[0];
	for (int i = 0; i < N; ++i) {
		cout << ans << '\n';
		if (i != N - 1) ans += X[p[i] + 1] - X[p[i]];
	}
	return 0;
}