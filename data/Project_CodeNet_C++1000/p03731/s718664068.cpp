#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
const int N = 5e5 + 5;
typedef long long ll; 
using namespace std;

int n, tm, m, t[N];
ll ans; 

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
	n = read <int> (), tm = m = read <int> ();
	for(int i = 1; i <= n; i++) t[i] = read <int> (); 
	for(int i = 2; i <= n; i++) ans += min(tm, t[i]) - t[i - 1], tm = t[i] + m; 
	printf("%lld\n", ans + m); 
	return 0; 
}
