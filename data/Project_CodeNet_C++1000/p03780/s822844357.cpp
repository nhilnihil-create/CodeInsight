#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <bitset>
const int N = 5005; 
using namespace std; 

int n, k, a[N]; 
bitset<N> sum; 

template < typename T >
inline T read()
{
	T x = 0, w = 1; char c = getchar();
	while(c < '0' || c > '9') { if(c == '-') w = -1; c = getchar(); }
	while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * w; 
}

bool check(int mid)
{
	if(a[mid] >= k) return 0; 
	sum.reset(), sum[0] = 1;
	for(int i = 1; i <= n; i++) if(i != mid && a[i] < k) sum |= sum << a[i];
	for(int i = k - a[mid]; i < k; i++)
		if(sum[i]) return 0; 
	return 1; 
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("cpp.in", "r", stdin);
#endif
	n = read <int> (), k = read <int> ();
	for(int i = 1; i <= n; i++) a[i] = read <int> ();
	sort(a + 1, a + n + 1);
	int l = 1, r = n, mid, ans = 0; 
	while(l <= r)
	{
		mid = (l + r) >> 1; 
		if(check(mid)) ans = mid, l = mid + 1; 
		else r = mid - 1; 
	}
	printf("%d\n", ans); 
	return 0; 
}
