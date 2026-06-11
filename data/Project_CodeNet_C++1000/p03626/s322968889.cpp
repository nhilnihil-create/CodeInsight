#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
const int N = 205;
const int mod = 1e9 + 7; 
using namespace std;

int n, ans, pos; 
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
	n = read <int> (), scanf("%s", s + 1), scanf("%s", s + 1);
	if(s[1] == s[2]) ans = 6, pos = 3; 
	else ans = 3, pos = 2; 
	while(pos <= n)
	{
		if(pos < n && s[pos] == s[pos + 1])
		{
			if(s[pos - 1] == s[pos - 2]) ans = 1ll * ans * 3 % mod;
			else ans = 1ll * ans * 2 % mod;
			pos += 2; 
		}
		else
		{
			if(s[pos - 1] == s[pos - 2]) ans = ans;
			else ans = 1ll * ans * 2 % mod;
			pos++; 
		}
	}
	printf("%d\n", ans); 
	return 0; 
}
