#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
long long D[1000009], P[1000009];

int main() {
	long long N; scanf("%lld",&N);
	D[1] = N; D[2] = N*N;
	P[1] = N; P[2] = N*N+N;
	for(int i=3; i<=N; i++) {
		D[i] = D[i-1] + (N-1)*(N-1) + (i-3 >= 0 ? P[i-3] : 0) + N-i+2;
		D[i] %= MOD;
		P[i] = (P[i-1] + D[i]) % MOD;
	}
	printf("%lld", D[N]);
	return 0;
}