#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int n, m, k, a[505][505], b[505][505];
char s[3][3]; 

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	s[0][0] = 'R', s[1][0] = 'G', s[0][1] = 'Y', s[1][1] = 'B';
	for(int op = 0, cnt = 0, i = -m - 1; i <= n; i++, cnt++)
	{
		if(cnt >= k) cnt = 0, op ^= 1; 
		for(int j = 1; j <= m; j++)
			if(i + j >= 1 && i + j <= n) a[i + j][j] = op; 
	}
	for(int op = 0, cnt = 0, i = n + m + 1; i >= 1; i--, cnt++)
	{
		if(cnt >= k) cnt = 0, op ^= 1; 
		for(int j = 1; j <= m; j++)
			if(i - j <= n && i - j >= 1) b[i - j][j] = op; 
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++) printf("%c", s[a[i][j]][b[i][j]]);
		puts("");
	}
	return 0; 
}
