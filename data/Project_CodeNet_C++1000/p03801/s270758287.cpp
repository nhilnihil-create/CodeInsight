#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAXN 100005

typedef long long lint;
typedef pair<int, int> pii;

int A[MAXN];
pii as[MAXN];
int p[MAXN], pn;
lint ans[MAXN];

int main() {
	int N;

	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", A + i);

	int h = 0;
	for(int i = 1; i <= N; i++) if(A[i] > h) {
		p[++pn] = i;
		h = A[i];
	}

	for(int i = 1; i <= N; i++) as[i] = make_pair(A[i], i);
	sort(as, as + N + 1);

	/*
	for(int i = 0; i <= pn; i++) printf("%d ", p[i]);
	printf("\n");
	for(int i = 0; i <= N; i++) printf("(%d, %d)", as[i].first, as[i].second);
	printf("\n");
	*/

	int k = N;
	while(as[k].second != p[pn]) k--;
	lint sum = 0ll;
	for(int i = pn; i > 0; i--) {
		//printf("i = %d, k = %d\n", i, k);
		ans[p[i]] += (lint) (N - k + 1) * (A[p[i]] - A[p[i - 1]]);
		for(k--; as[k].second != p[i - 1]; k--)
			ans[p[i]] += as[k].first - A[p[i - 1]];
	}

	for(int i = 1; i <= N; i++) printf("%lld\n", ans[i]);
	return 0;
}
