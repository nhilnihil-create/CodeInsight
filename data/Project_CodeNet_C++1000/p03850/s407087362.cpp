#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
const int N = 1e5 + 5;
typedef long long ll; 
using namespace std;

int n, a[N], b[N];
ll f[N][3];
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
	n = read <int> (), a[1] = read <int> ();
	for(int i = 2; i <= n; i++)
	{
		scanf("%s", s + 1), b[i] = s[1] == '-' ? 0 : 1;
		a[i] = read <int> (); 
	}
	memset(f, -0x3f, sizeof(f)), f[1][0] = a[1];
	for(int i = 2; i <= n; i++)
	{
		if(b[i])
		{
			f[i][0] = max(f[i - 1][0] + a[i], f[i - 1][1] - a[i]); 
			f[i][1] = max(f[i - 1][1] - a[i], f[i - 1][2] + a[i]); 
			f[i][2] = f[i - 1][2] + a[i]; 
		}
		else
		{
			f[i][0] = max(f[i - 1][0] - a[i], f[i - 1][1] + a[i]); 
			f[i][1] = max(f[i - 1][1] + a[i], f[i - 1][2] - a[i]);
			f[i][1] = max(f[i][1], f[i - 1][0] - a[i]);
			f[i][2] = max(f[i - 1][2] - a[i], f[i - 1][1] + a[i]); 
		}
	}
	printf("%lld\n", f[n][0]); 
	return 0; 
}