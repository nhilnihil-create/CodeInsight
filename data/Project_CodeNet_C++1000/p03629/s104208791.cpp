#include<bits/stdc++.h>
using namespace std;
char s[300001];
int n,dp[300001],to[300001][31];
int main()
{
	scanf("%s",s+1);
	n=(int)strlen(s+1);
	for(int i=0;i<26;i++)to[n][i]=n+1;
	for(int i=n-1;i>=0;i--)
	{
		memcpy(to[i],to[i+1],sizeof(to[i]));
		to[i][s[i+1]-'a']=i+1;
	}
	for(int i=n;i>=0;i--)
	{
		dp[i]=0x3f3f3f3f;
		for(int j=0;j<26;j++)dp[i]=min(dp[i],dp[to[i][j]]+1);
	}
	int p=0;
	while(p<=n)
	{
		for(int i=0;i<26;i++)
			if(dp[p]==dp[to[p][i]]+1)
			{
				putchar(i+'a');
				p=to[p][i];
				break;
			}
	}
	putchar('\n');
}
