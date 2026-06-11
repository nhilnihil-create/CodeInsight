#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
const int N = 1e6 + 5;
typedef long long ll;
#define int ll
using namespace std; 

int n, a[N], ans1, ans2; 

template < typename T >
inline T read()
{
	T x = 0, w = 1; char c = getchar();
	while(c < '0' || c > '9') { if(c == '-') w = -1; c = getchar(); }
	while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * w; 
}

int mabs(int x) { return x < 0 ? -x : x; }

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("cpp.in", "r", stdin);
#endif
	n = read <int> ();
	for(int i = 1; i <= n; i++) a[i] = read <int> (); 
	for(int sum = 0, i = 1; i <= n; i++)
	{
		if(i & 1)
		{
			if(sum + a[i] > 0) { sum += a[i]; continue; }
			ans1 += mabs(sum + a[i]) + 1, sum = 1; 
		}
		else
		{
			if(sum + a[i] < 0) { sum += a[i]; continue; }
			ans1 += mabs(sum + a[i]) + 1, sum = -1; 
		}
	}
	for(int sum = 0, i = 1; i <= n; i++)
	{
		if(!(i & 1))
		{
			if(sum + a[i] > 0) { sum += a[i]; continue; }
			ans2 += mabs(sum + a[i]) + 1, sum = 1; 
		}
		else
		{
			if(sum + a[i] < 0) { sum += a[i]; continue; }
			ans2 += mabs(sum + a[i]) + 1, sum = -1; 
		}
	}
	printf("%lld\n", min(ans1, ans2)); 
	return 0; 
}
