#include <cstdio>
#include <algorithm>

typedef long long LL;
const int MN = 100005;

int N, L, T, X[MN], W[MN], Y[MN], Id[MN];
int X1[MN], X2[MN], C1, C2;
int Ans[MN];

inline LL Q1(LL v) {
	LL w = (v % L + L) % L, k = (v - w) / L;
	return std::upper_bound(X1, X1 + C1, w) - X1 + k * C1;
}
inline LL Q2(LL v) {
	LL w = (v % L + L) % L, k = (v - w) / L;
	return std::upper_bound(X2, X2 + C2, w) - X2 + k * C2;
}

int main() {
	scanf("%d%d%d", &N, &L, &T);
	for (int i = 0; i < N; ++i) {
		scanf("%d%d", &X[i], &W[i]);
		if (W[i] == 1) X1[C1++] = X[i];
		if (W[i] == 2) X2[C2++] = X[i];
	}
	for (int i = 0; i < N; ++i) {
		Y[i] = X[i];
		if (W[i] == 1) {
			Y[i] = (Y[i] + T) % L;
			Id[i] = (i + Q2(X[i] + 2ll * T) - Q2(X[i])) % N;
		}
		if (W[i] == 2) {
			Y[i] = (Y[i] - T % L + L) % L;
			Id[i] = ((i - Q1(X[i] - 1) + Q1(X[i] - 2ll * T - 1)) % N + N) % N;
		}
		Ans[Id[i]] = Y[i];
	}
	for (int i = 0; i < N; ++i) printf("%d\n", Ans[i]);
	return 0;
}