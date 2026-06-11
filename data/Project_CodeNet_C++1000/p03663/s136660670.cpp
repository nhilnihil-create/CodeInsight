#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
typedef long long ll;
#define int ll
using namespace std; 

int a[15], len; 
char s[5]; 

template < typename T >
inline T read()
{
	T x = 0, w = 1; char c = getchar();
	while(c < '0' || c > '9') { if(c == '-') w = -1; c = getchar(); }
	while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * w; 
}

bool query(ll x)
{
	printf("? %lld\n", x), fflush(stdout), scanf("%s", s + 1);
	return s[1] == 'Y'; 
}

signed main()
{
	int x = 1e9;
	if(query(x))
	{
		for(int i = 9; i; i--)
		{
			if(!query(x - 1)) break; 
			x /= 10; 
		}
		printf("! %d\n", x);
		return 0; 
	}
	for(int i = 9; i; i--)
	{
		x /= 10;
		if(query(x)) break; 
	}
	int l = x + 1, r = x * 10 - 1, ans, mid;
	while(l <= r)
	{
		mid = (l + r) >> 1;
		if(query(mid * 10)) r = mid - 1, ans = mid;
		else l = mid + 1; 
	}
	printf("! %d\n", ans); 
	return 0; 
}
