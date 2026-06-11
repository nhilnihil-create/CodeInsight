#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<long long>A(3 * N);
	for (int i = 0; i < 3 * N; ++i) {
		cin >> A[i];
	}

	//大きいものを入れたい
	vector<long long>Lsum(N + 1);
	priority_queue<long long, vector<long long>, greater<long long> > Lque;
	for (int i = 0; i < N; ++i) {
		Lque.push(A[i]);
		Lsum[0] += A[i];
	}
	for (int i = 0; i < N; ++i) {
		long long x = A[N + i];
		Lsum[i + 1] = Lsum[i];
		long long y = Lque.top();
		if (y < x) {
			Lque.pop();
			Lque.push(x);
			Lsum[i + 1] -= y;
			Lsum[i + 1] += x;
		}
	}

	//小さいものを入れたい
	vector<long long>Rsum(N + 1);
	priority_queue<long long> Rque;
	for (int i = 0; i < N; ++i) {
		Rque.push(A[3 * N - 1 - i]);
		Rsum[N] += A[3 * N - 1 - i];
	}
	for (int i = 0; i < N; ++i) {
		long long x = A[2 * N - 1 -i];
		Rsum[N - 1 - i] = Rsum[N - i];
		long long y = Rque.top(); 
		if (y > x) {
			Rque.pop();
			Rque.push(x);
			Rsum[N - 1 - i] -= y;
			Rsum[N - 1 - i] += x;
		}
	}

	long long ans = -1e18;
	for (int i = 0;i<=N;++i) {
		ans = max(ans ,Lsum[i]-Rsum[i]);
	}
	cout << ans << endl;
	return 0;
}
