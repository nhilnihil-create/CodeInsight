#include <cstdio>

int N, x;
long long ans;
int count[100010];
const long long MOD = 1000000007;

inline int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	scanf("%d", &N);
	ans = 1LL;
	int stocked = 0;
	int pen = 0;
	for(int i=1; i<=N; i++) {
		scanf("%d", &x);
		int want;
		want = stocked*2;
		if(x > want) {
			stocked ++;
		}
		if(x < want) {
			pen ++;
		}
		//printf("%d:%d %d\n", x, pen, i-pen);
		count[pen] ++;
		if(x == want) {
			pen ++;
		}
	}
	int curr = 0;
	for(int i=0; i<N; i++) {
		curr += count[i];
		//printf("i=%d: %d\n", i, curr-i);
		ans = ans * (curr-i) % MOD;
	}
	printf("%d\n", (int)ans);
	return 0;
}