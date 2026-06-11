#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int N;
	long long L, T;
	scanf("%d %lld %lld", &N, &L, &T);
	int W[N];
	long long X[N], Xf[N];
	for (int i = 0; i < N; ++i) scanf("%lld %d", &X[i], &W[i]);
	for (int i = 0; i < N; ++i) {
		if (W[i] == 1) Xf[i] = (X[i] + T) % L;
		else Xf[i] = ((X[i] - T) % L + L) % L;
	}
	long long cnt = 0, sp = Xf[0];
	for (int i = 1; i < N; ++i) {
		if (W[i] != W[0]) {
			if (W[0] == 1 && 2 * T > X[i] - X[0]) cnt += (2 * T - X[i] + X[0] + L - 1) / L;
			else if (W[0] == 2 && 2 * T > L + X[0] - X[i]) cnt -= (2 * T - X[0] + X[i] - 1) / L;
		}
	}
	cnt = (cnt % N + N) % N;
	sort(Xf, Xf + N);
	int fidx;
	if (W[0] == 1) fidx = lower_bound(Xf, Xf + N, sp) - Xf;
	else fidx = upper_bound(Xf, Xf + N, sp) - Xf - 1;
	long long ans[N];
	for (int i = 0; i < N; ++i) ans[(cnt + i) % N] = Xf[(fidx + i) % N];
	for (int i = 0; i < N; ++i) printf("%lld\n", ans[i]);
	return 0;
}