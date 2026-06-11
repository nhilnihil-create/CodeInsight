#include<iostream>
#include<cstring>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 1e5 + 3;
ll x[maxn], y[maxn];
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i<n; ++i)
	scanf("%lld", &x[i]);
	for (int i = 0; i<m; ++i)
	scanf("%lld", &y[i]);
	ll W = 0, H = 0;
	for (int i = 0, j = n - 1; i < j; ++i, --j)
		W = (W + (x[j] - x[i])*(j - i) % mod) % mod;
	for (int i = 0, j = m - 1; i < j; ++i, --j)
		H = (H + (y[j] - y[i])*(j - i) % mod) % mod;
	
	printf("%lld\n", (W*H) % mod);

}