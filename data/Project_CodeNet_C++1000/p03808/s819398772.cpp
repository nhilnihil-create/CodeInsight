#include <cstdio>
 
typedef long long LL;
const int MN = 100005;
 
int N, A[MN];
LL S;
 
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) scanf("%d", &A[i]), S += A[i];
	if (S % ((LL)N * (N + 1) / 2) != 0) return puts("NO"), 0;
	LL C = S / ((LL)N * (N + 1) / 2);
	for (int i = 1; i <= N; ++i) {
		LL k = C - (A[i % N + 1] - A[i]);
		if (k < 0 || k % N != 0) return puts("NO"), 0;
	}
  
  
	puts("YES");
	return 0;
}