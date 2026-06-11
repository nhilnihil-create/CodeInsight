#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1000009;
const int MOD = 1e9+7;
LL f[maxn], n, sum;

int main(){
	scanf("%lld", &n);
	f[1] = n; f[2] = n*n%MOD;
	for (int i=3; i<=n; i++){
		f[i] = (f[i-1] + (n-1)*(n-1) + sum + (n-i+2)) % MOD;
		sum = (sum + f[i-2]) % MOD;
	}
	printf("%lld\n", f[n]);
	return 0;
}