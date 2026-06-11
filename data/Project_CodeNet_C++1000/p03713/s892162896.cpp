#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
const int N = 2e5 + 5;
typedef long long ll;
const ll INF = 1e15; 
using namespace std;

int n, m;
ll ans = INF; 

template < typename T >
inline T read()
{
	T x = 0, w = 1; char c = getchar();
	while(c < '0' || c > '9') { if(c == '-') w = -1; c = getchar(); }
	while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * w; 
}

ll mabs(ll x) { return x > 0 ? x : -x; }

int main()
{
#ifndef ONLINE_JUDGE
	freopen("cpp.in", "r", stdin); 
#endif
	n = read <int> (), m = read <int> ();
	if(n % 3 == 0 || m % 3 == 0) { puts("0"); return 0; }
	for(int l = (n + 1) / 2, r = n / 2, i = 1; i <= m; i++)
		ans = min(ans, max(max(mabs(1ll * l * i - 1ll * n * (m - i)), mabs(1ll * r * i - 1ll * n * (m - i))), mabs(1ll * l * i - 1ll * r * i))); 
	for(int l = (m + 1) / 2, r = m / 2, i = 1; i <= n; i++)
		ans = min(ans, max(max(mabs(1ll * l * i - 1ll * m * (n - i)), mabs(1ll * r * i - 1ll * m * (n - i))), mabs(1ll * l * i - 1ll * r * i)));
	ans = min(ans, 1ll * min(n, m)); 
	printf("%lld\n", ans); 
	return 0; 
}
