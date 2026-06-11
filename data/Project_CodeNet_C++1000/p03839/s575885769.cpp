#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int n, k;
ll ans;
ll l[maxn], r[maxn], sum[maxn];
int a[maxn];
int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i) 
	{
		scanf("%d", &a[i]);
		sum[i] = sum[i - 1] + a[i];
	}
	for(int i = 1; i <= n; ++i) l[i] = l[i - 1] + max(a[i], 0); 
	for(int i = n; i; --i) r[i] = r[i + 1] + max(a[i], 0);
	for(int i = k; i <= n; ++i) ans = max(ans, r[i + 1] + l[i - k] + max(sum[i] - sum[i - k], 0ll));
	cout << ans << endl;
	return 0;
}