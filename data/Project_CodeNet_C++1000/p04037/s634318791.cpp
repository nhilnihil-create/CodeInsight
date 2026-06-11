#include<bits/stdc++.h>
#define For(i, j, k) for(int i = j; i <= k; ++i)
using namespace std;

inline void File() {
#ifndef ONLINE_JUDGE
	freopen("AGC002E.in", "r", stdin);
	freopen("AGC002E.out", "w", stdout);
#endif
}

const int N = 1e5 + 10;
int A[N], n;

inline bool cmp(int a, int b) { return a > b; }

int main() {
	scanf("%d", &n);
	For(i, 1, n) scanf("%d", &A[i]);
	sort(A + 1, A + 1 + n, cmp);
	int tmp = 1;
	while(A[tmp] >= tmp) ++tmp; --tmp;
	int ans = (A[tmp] - tmp) & 1, res = 0;
	For(i, tmp + 1, n) {
		if(A[i] == tmp) res++;
		else break;
	}
	ans |= (res & 1);
	printf("%s\n", ans ? "First" : "Second");
	return 0;
}