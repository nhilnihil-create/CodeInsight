#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;

const int MAXN = 1e6 + 10;
int N;
int A[MAXN];
int x[MAXN], rk[MAXN];
int cnt[MAXN];

int main() {
	register int i, j = 0;
	scanf("%d", &N);
	for(i = 1; i <= N; ++i)
		scanf("%d", x + i), rk[i] = i, cnt[i] = N;
	if(N == 1) return puts(x[1] == 1 ? "Yes\n1" : "No"), 0;
	sort(rk + 1, rk + N + 1, [&](int a, int b) {return x[a] < x[b];});
	for(i = 1; i <= N; ++i) {
		while(cnt[rk[i]] > N - rk[i] + 1) {
			--cnt[rk[i]];
			while(j <= N * N && A[j + 1]) ++j;
			if(j > N * N)  return puts("No"), 0;
			A[++j] = rk[i];
		}
		if(A[x[rk[i]]]) return puts("No"), 0;
		A[x[rk[i]]] = rk[i]; --cnt[rk[i]];
	}
	i = 1;
	for(; j <= N * N; ++j) {
		if(A[j]) continue;
		if(cnt[rk[i]] > 0) --cnt[rk[i]], A[j] = rk[i];
		else {while(cnt[rk[i]] == 0) ++i; --cnt[rk[i]]; A[j] = rk[i];}
		if(j <= x[rk[i]]) return puts("No"), 0;
		if(i > N) return puts("No"), 0;
	}
	puts("Yes");
	for(i = 1; i <= N * N; ++i)
		printf("%d%c", A[i], " \n"[i == N * N]);
	return 0;
}