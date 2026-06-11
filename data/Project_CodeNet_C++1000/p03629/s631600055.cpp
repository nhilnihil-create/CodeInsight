#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f; 
using namespace std;

int n, f[N][27], pos[N], nxt[N], g[N][27], sum[N][27]; 
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
	for(int tmp, i = n + 1; i >= 1; i--)
	{
		for(int j = 1; j <= 26; j++)
		{
			if(s[i] == 'a' + j - 1)
			{
				tmp = INF; 
				for(int k = 26; k; k--)
					if(f[i + 1][k] <= tmp) tmp = f[i + 1][k], nxt[i] = g[i + 1][k]; 
				f[i][j] = tmp + 1, g[i][j] = i, sum[i][j] = sum[i + 1][j] + 1; 
			}
			else f[i][j] = f[i + 1][j], g[i][j] = g[i + 1][j], sum[i][j] = sum[i + 1][j]; 
		}
		pos[s[i] - 'a' + 1] = i; 
	}
	for(int i = 1; i <= 26; i++) if(!pos[i]) { putchar('a' + i - 1), puts(""); return 0; }
	int tmp = INF, id = 0; 
	for(int i = 26; i >= 1; i--) if(f[pos[i]][i] <= tmp) tmp = f[pos[i]][i], id = i; 
	id = pos[id]; 
	while(id)
	{
		putchar(s[id]); 
		if(!nxt[id]) break;
		id = nxt[id]; 
	}
	for(int i = 1; i <= 26; i++)
		if(!sum[id + 1][i]) { putchar('a' + i - 1), puts(""); return 0; }
	return 0; 
}
