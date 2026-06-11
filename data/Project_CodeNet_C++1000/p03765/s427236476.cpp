#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
const int N = 1e5 + 5;
const int mod = 1e9 + 7; 
using namespace std; 

int n, m, q, sum1[N], sum2[N]; 
char s[N]; 

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
	scanf("%s", s + 1), n = strlen(s + 1);
	for(int i = 1; i <= n; i++) sum1[i] = sum1[i - 1] + (s[i] == 'A' ? 2 : 1);
	scanf("%s", s + 1), m = strlen(s + 1);
	for(int i = 1; i <= m; i++) sum2[i] = sum2[i - 1] + (s[i] == 'A' ? 2 : 1);
	q = read <int> (); int a, b, c, d; 
	while(q--)
	{
		a = read <int> (), b = read <int> (), c = read <int> (), d = read <int> ();
		if((sum1[b] - sum1[a - 1]) % 3 == (sum2[d] - sum2[c - 1]) % 3) puts("YES");
		else puts("NO"); 
	}
	return 0; 
}
