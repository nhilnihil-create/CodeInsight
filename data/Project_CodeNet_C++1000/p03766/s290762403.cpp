#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll MOD = 1000000007;
ll s[1005999];

int main()
{
	int n;
	scanf("%lld", &n);
	s[0] = 1, s[1] = s[0] + n, s[2] = (s[1] + 1ll*n*n) % MOD;
	for(int i=3; i<=n; i++) s[i] = (2*s[i-1] - s[i-2] + s[i-3] + 1ll*(n-1)*(n-1) + (n-i+1) + MOD) % MOD;
	printf("%lld\n", (s[n]-s[n-1]+MOD) % MOD);
	return 0;
}