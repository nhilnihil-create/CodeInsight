#include <bits/stdc++.h>
using namespace std;

long memo[110000];

const int MOD = 1000000007;

long func(int a){
	if(memo[a] != 0) return memo[a];
	if(a == 1) return memo[a] = 1;
	memo[a-1] = func(a - 1) % MOD;
	return memo[a] = a * memo[a-1] % MOD;
}

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	long ans = 0;
	if(abs(n - m) > 1) printf("0\n");
	else{
		if(n == m) {
			ans = func(n) * func(m) * 2 % MOD;
		}else{
			ans = func(n) * func(m) % MOD;
		}
		printf("%ld\n", ans);
	}
}
