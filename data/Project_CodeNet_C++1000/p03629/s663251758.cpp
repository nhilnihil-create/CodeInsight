#include <cstring>
#include <cstdio>
char str[200005], ans[200005]; 
int nxt[200005][35], dp[200005], ch[200005]; 
int main()
{
	// freopen("ARC081-E.in", "r", stdin); 
	scanf("%s", str); 
	int n = strlen(str); 
	for (int i = 0; i < 26; i++)
		nxt[n + 1][i] = n + i + 1; 
	for (int i = n; i >= 0; i--)
	{
		memcpy(nxt[i], nxt[i + 1], sizeof(nxt[i + 1])); 
		if (i)
			nxt[i][str[i - 1] - 'a'] = i; 
	}
	memset(dp, 0x3f, sizeof(dp)); 
	for (int i = n + 1; i <= n + 26; i++)
		dp[i] = 0; 
	for (int i = n; i >= 0; i--)
	{
		for (int j = 0; j < 26; j++)
		{
			if (dp[nxt[i + 1][j]] + 1 < dp[i])
			{
				dp[i] = dp[nxt[i + 1][j]] + 1;
				ch[i] = j; 
			}
		}
	}
	int x = 0, len = 0; 
	while (x < n)
	{
		ans[len++] = ch[x] + 'a'; 
		x = nxt[x + 1][ch[x]]; 
	}
	puts(ans); 
	return 0; 
}
