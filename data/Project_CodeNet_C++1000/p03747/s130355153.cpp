#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	int N; long long L, T;
	cin >> N >> L >> T;
	vector<long long> X(N);
	vector<int> W(N);
	for (int i = 0; i < N; ++i) cin >> X[i] >> W[i];
	
	vector<long long> tmp(N);
	for (int i = 0; i < N; i++) {
		if (W[i] == 1) tmp[i] = (X[i] + T) % L;
		else tmp[i] = ((X[i] - T) % L + L) % L;
	}
	sort(tmp.begin(), tmp.end());
	
	long long cnt = 0;
	for (int i = 0; i < N; i++) {
		if (W[i] == 1) cnt -= (T - (L - X[i]) + L) / L;
		else cnt += (T - (X[i] + 1) + L) / L;
	}
	cnt = (cnt % N + N) % N;
	vector<long long> res(N);
	for (int i = 0; i < N; i++) res[(i + cnt) % N] = tmp[i];
	for (int i = 0; i < N; i++) cout << res[i] << endl;

	return 0;
}