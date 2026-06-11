#include <bits/stdc++.h>
using namespace std;
#define all(V) V.begin(),V.end()
using ll = long long;

int main(){
	int N, K;
	cin >> N >> K;
	vector<ll> A(N), L(N), R(N), S(N, 0);
	if (N == K) {
		for (int i = 0;i < N;i++)cin >> A[i];
		for (int i = 1;i < N;i++)A[i] += A[i - 1];
		cout << max(0LL, A[N - 1]) << endl;
		return 0;
	}
	for (int i = 0;i < N;i++)
		cin >> A[i];
	L[0] = max(A[0], 0LL);
	for (int i = 1;i < N;i++) {
		if(A[i]>0)L[i] = L[i - 1] + A[i];
		else L[i] = L[i - 1];
	}
	R[N - 1] = max(A[N - 1], 0LL);
	for (int i = N - 2;i >= 0;i--) {
		if(A[i]>0)R[i] = R[i + 1] + A[i];
		else R[i] = R[i + 1];
	}


	ll sum = 0;
	for (int i = 0;i < K;i++) {
		sum += A[i];
	}
	S[K - 1] = sum;
	for (int i = K;i < N;i++) {
		sum += A[i];
		sum -= A[i - K];
		S[i] = sum;
	}

	ll ans = max(max(S[K - 1], 0LL) + R[K], max(S[N - 1], 0LL) + L[N - 1 - K]);
	//cout << R[K] << " " << L[N - 1 - K] << endl;
	for (int i = K;i < N - 1;i++) {
		ans = max(max(S[i], 0LL) + L[i - K] + R[i + 1], ans);
	}

	cout << ans << endl;
}