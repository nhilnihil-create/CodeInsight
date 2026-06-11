#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
const int N = 1e5 + 5; 
using namespace std;

int n, a[N], c[N], cnt, ans; 

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
	for(int i = 1; i <= n; i++)
	{
		a[i] = read <int> (), c[a[i]]++; 
		if(c[a[i]] == 1) ans++; 
		if(c[a[i]] >= 3) c[a[i]] -= 2; 
	}
	for(int i = 1; i <= 100000; i++)
		if(c[i] == 2) cnt++;
	while(cnt >= 3) cnt -= 2;
	if(cnt & 1) printf("%d\n", ans - 1);
	else printf("%d\n", ans); 
	return 0; 
}
