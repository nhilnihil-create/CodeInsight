#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
char s[maxn];
int trans[maxn][26], f[maxn], path[maxn];
int main()
{
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	for(int j = 0; j < 26; ++j) trans[n][j] = n + 1;
	for(int i = n - 1; ~i; --i)
	{
		for(int j = 0; j < 26; ++j)
			trans[i][j] = trans[i + 1][j];
		trans[i][s[i + 1] - 'a'] = i + 1;
	}
	for(int i = n; ~i; --i)
	{
		f[i] = n + 1;
		for(int j = 0; j < 26; ++j)
			if(f[trans[i][j]] + 1 < f[i])
			{
				f[i] = f[trans[i][j]] + 1;
				path[i] = j;
			}
	}
	int cur = 0;
	while(cur != n + 1)
	{
		putchar(path[cur] + 'a');
		cur = trans[cur][path[cur]];
	}
	return 0;
}