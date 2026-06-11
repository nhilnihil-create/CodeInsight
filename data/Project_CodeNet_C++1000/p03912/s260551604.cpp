#include "bits/stdc++.h"
using namespace std;

int main() {
	long long N, M, ANS = 0;
	vector<vector<long long> > V;
	cin >> N >> M;
	V.resize(M);
	for (int i = 0; i < N; i++) {
		long long X;
		cin >> X;
		V[X % M].push_back(X);
	}
	for (int i = 1; i * 2 < M; i++) {
		sort(V[i].begin(), V[i].end()), sort(V[M - i].begin(), V[M - i].end());
		if (V[i].size() < V[M - i].size()) swap(V[i], V[M - i]);
		long long COUNT = V[M - i].size();
		long long D = V[i].size() - V[M - i].size();
		long long Even = V[i].size();
		map<long long, long long> mp = {};
		for (long long j : V[i]) mp[j] = (mp[j] + 1) % 2;
		for (auto it = mp.begin(); it != mp.end(); it++) {
			Even -= it->second;
		}
		Even /= 2;
		COUNT += min(Even, (long long)((V[i].size() - V[M - i].size()) / 2));
		ANS += COUNT;
	}
	ANS += V[0].size() / 2;
	if (M % 2 == 0) ANS += V[M / 2].size() / 2;
	cout << ANS << endl;
}