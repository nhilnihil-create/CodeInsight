#include<iostream>
#include<bitset>
#include<algorithm>

using namespace std;

typedef long long ll;

int N, K;
ll A[5000 + 10];

bool f(int pos) {
	//A[pos]は不必要か？
	bitset<5000 + 30> dp;
	dp[0] = 1;
	for (int i = 0; i < N; i++) {
		if (i == pos)continue;
		if (A[i] <= K)dp |= (dp << A[i]);
	}
	if (K - A[pos] <= 0)return false;
	for (int i = (K - A[pos]); i < K; i++) {
		if (dp[i]) {
			return false;
		}
	}
	return true;
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(A, A + N);
	
	int l = 0, u = N - 1;
	while (u - l > 1) {
		int mid = (u + l) / 2;
		if (f(mid))l = mid;
		else u = mid;
	}

	if (f(u))cout << u + 1 << endl;
	else if (f(l))cout << l + 1 << endl;
	else cout << 0 << endl;
	
	return 0;
}
