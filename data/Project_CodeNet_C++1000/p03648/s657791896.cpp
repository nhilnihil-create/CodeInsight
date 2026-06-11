#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;

typedef long long ll;
const int MAXN = 50 + 10;
ll K; ll N;
ll A[MAXN];

int main() {
	register int i;
	scanf("%lld", &K);
	N = 50;
	for(i = 0; i < N; ++i)
		A[i] = (K / N) - (K % N) + (N - 1) + (i < K % N ? N + 1 : 0);
	printf("%lld\n", N);
	for(i = 0; i < N; ++i)
		printf("%lld\n", A[i]);
	return 0;
}