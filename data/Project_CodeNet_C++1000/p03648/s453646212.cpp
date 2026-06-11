#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 50 + 10;
int n = 50;
ll k;
int main()
{
	scanf("%lld", &k);
	ll base = k / n + 49;
	int l = k % n;
	printf("%d\n", n);
	for(int i = 1; i <= n - l; ++i) printf("%lld ", base - l);
	for(int i = n - l + 1; i <= n; ++i) printf("%lld ", base + 51 - l);
	return 0;
}