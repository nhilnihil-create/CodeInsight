#include <cstdio>

const long long int MOD = 1e9 + 7;

int main(){
	int n, m;
	long long int x, y, xSum=0, ySum=0;
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; ++i){
		scanf("%lld", &x);
		xSum += (2*i + 1 - n) * x;
		xSum %= MOD;
	}
	for(int i=0; i<m; ++i){
		scanf("%lld", &y);
		ySum += (2*i + 1 - m) * y;
		ySum %= MOD;
	}
	printf("%lld\n", xSum * ySum % MOD);
}
