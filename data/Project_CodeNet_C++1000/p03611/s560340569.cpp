#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
const int N = 1e5 + 5; 
using namespace std; 

int a[N], c[N], n, ans; 

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
	n = read <int> ();
	for(int i = 1; i <= n; i++) c[a[i] = read <int> ()]++;
	for(int i = 1; i <= 100000; i++) ans = max(ans, c[i - 1] + c[i] + c[i + 1]);
	printf("%d\n", ans); 
	return 0; 
}
