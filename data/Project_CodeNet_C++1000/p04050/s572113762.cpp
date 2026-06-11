#include <bits/stdc++.h>

using namespace std;

int A[105];
int N, M;
vector<int> v;

int main() {
	scanf("%d%d", &N, &M);
	int o = 0;
	for(int i = 1; i <= M; i++) {
		scanf("%d", &A[i]);
		if(A[i] & 1) o++;
	}
	if(o > 2) { puts("Impossible"); return 0; }
	if(M == 1) {
		if(N == 1) printf("1\n1\n1\n");
		else printf("%d\n2\n%d %d\n", A[1], A[1] - 1, 1);
		return 0;
	}

	for(int i = 1; i <= M; i++) if(A[i] & 1) swap(A[i], A[1]);
	for(int i = 2; i <= M; i++) if(A[i] & 1) swap(A[i], A[M]);

	for(int i = 1; i <= M; i++) printf("%d ", A[i]); puts("");

	v.push_back(A[1] + 1);
	for(int i = 2; i < M; i++) v.push_back(A[i]);
	if(A[M] > 1) v.push_back(A[M] - 1);
	printf("%d\n", v.size());
	for(int i : v) printf("%d ", i); puts("");

	return 0;
}