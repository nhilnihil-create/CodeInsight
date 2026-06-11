#include <algorithm>
#include <cstdio>
typedef long long ll; 
ll k[100005], b[100005]; 
int arr[100005], n, m;
inline void work(int x, int y)
{
	b[x] += x; 
	k[x]--; 
	k[y]++; 
	if (x < y)
	{
		b[1] += y - x; 
		b[y] -= x; 
	}
	else
	{
		b[1] += y; 
		b[y] += m - x; 
		k[1]--; 
	}
}
int main()
{
	// freopen("ARC077-E.in", "r", stdin); 
	scanf("%d%d", &n, &m); 
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i); 
	for (int i = 0; i < n - 1; i++)
		work(arr[i] + 1, arr[i + 1] + 1); 
	ll ans = 1e18; 
	for (int i = 1; i <= m; i++)
	{
		k[i] += k[i - 1]; 
		b[i] += b[i - 1]; 
		ans = std::min(ans, k[i] * i + b[i]); 
	}
	printf("%lld\n", ans);
	return 0; 
}
