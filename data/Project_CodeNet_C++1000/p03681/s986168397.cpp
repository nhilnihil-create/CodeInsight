#include <bits/stdc++.h>
using namespace std;

long memo[110000];

const int MOD = 1000000007;
template <typename T> long pow_mod(T base, T exp, const T modulus = 1000000007) {
	base %= modulus;
	long result = 1L;
	while (exp > 0) {
		if (exp & 1) result = (result * base) % modulus;
		base = (base * base) % modulus;
		exp >>= 1;
	}
	return result;
}

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
			ans = pow_mod(func(n), 2L) * 2 % MOD;
		}else{
			int b = max(n, m);
			ans = pow_mod(func(b - 1), 2L) * b % MOD;
		}
		printf("%ld\n", ans);
	}
}
