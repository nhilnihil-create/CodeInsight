#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
const int N = 1e5 + 5;
typedef long long ll;
const ll INF = 1e16; 
using namespace std;

int n, m, a[N]; 
ll ans = INF, c[N]; 

template < typename T >
inline T read()
{
	T x = 0, w = 1; char c = getchar();
	while(c < '0' || c > '9') { if(c == '-') w = -1; c = getchar(); }
	while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * w; 
}

void add(int l, int r, int x, int y)
{
	if(l > r) return; 
	int k = r - l;
	c[l] += x, c[l + 1] += y - x; 
	c[r + 1] -= x + y * (k + 1), c[r + 2] += x + y * k; 
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("cpp.in", "r", stdin); 
#endif
	n = read <int> (), m = read <int> ();
	for(int i = 1; i <= n; i++) a[i] = read <int> (); 
	for(int l, r, i = 2; i <= n; i++)
	{
		l = a[i - 1], r = a[i]; 
		if(a[i] >= a[i - 1])
		{
			add(l + 1, r, r - l, -1);
			add(1, l, r - l, 0), add(r + 1, m, r - l, 0); 
		}
		else
		{
			add(l + 1, m, r + m - l, -1), add(1, r, r, -1);
			add(r + 1, l, r + m - l, 0); 
		}
	}
	for(int i = 1; i <= m; i++) c[i] += c[i - 1]; 
	for(int i = 1; i <= m; i++) c[i] += c[i - 1]; 
	for(int i = 1; i <= m; i++) ans = min(ans, 1ll * c[i]); 
	printf("%lld\n", ans); 
	return 0; 
}
