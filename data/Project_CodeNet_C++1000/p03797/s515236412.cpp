#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
typedef long long ll; 
using namespace std;

ll n, m, ans; 

template < typename T >
inline T read()
{
	T x = 0, w = 1; char c = getchar();
	while(c < '0' || c > '9') { if(c == '-') w = -1; c = getchar(); }
	while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * w; 
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("cpp.in", "r", stdin); 
#endif
	n = read <ll> (), m = read <ll> ();
	if(m < n * 2) { printf("%lld\n", m / 2); return 0; }
	ans = n, m -= n * 2;
	printf("%lld\n", ans + m / 4); 
	return 0; 
}
