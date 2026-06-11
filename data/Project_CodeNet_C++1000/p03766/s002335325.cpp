#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
const int mod = 1000000007;
int n,ans[N],sum;
int main() {
	scanf("%d",&n);
	ans[n] = n;
	ans[n-1] = (long long)n * n % mod;
	for(int i = n - 2; i >= 1; i--) {
		sum = (sum + ans[i + 3]) % mod;
		ans[i] = ans[i + 1];
		ans[i] = (ans[i] + (long long)(n - 1) * (n - 1) % mod) % mod;
		ans[i] = (ans[i] + sum) % mod;
		ans[i] = (ans[i] + i + 1) % mod;
	}
	printf("%d\n",ans[1]);
	return 0;
}