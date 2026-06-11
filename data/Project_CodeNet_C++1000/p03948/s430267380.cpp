#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
const int N = 1e5 + 5;
typedef long long ll; 
using namespace std;

int n, m, a[N], mx[N], ans, cnt; 

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
	n = read <int> (), m = read <int> ();
	for(int i = 1; i <= n; i++) a[i] = read <int> ();
	for(int i = n; i >= 1; i--) mx[i] = max(mx[i + 1], a[i]);
	for(int i = 1; i <= n; i++)
		if(mx[i + 1] - a[i] > 0 && mx[i + 1] - a[i] > ans) ans = mx[i + 1] - a[i], cnt = 1;
		else if(mx[i + 1] - a[i] == ans) cnt++;
	printf("%d\n", cnt); 
	return 0; 
}
