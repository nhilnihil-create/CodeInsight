#include<bits/stdc++.h>
using namespace std;
char str[200005];
int dp[200005];
int Next[200005][30];
int main()
{
	while(scanf("%s",str)!=EOF)
	{
	
	int len=strlen(str);
	for(int i=0;i<26;i++)//以Len结尾的i出现的位置 
		Next[len][i]=len;
	for(int i=len-1;i>=0;i--)
	{
		for(int j=0;j<26;j++)
			Next[i][j]=((str[i]==(j+'a'))?i:Next[i+1][j]);
	}
	dp[len]=1;
	for(int i=len-1;i>=0;i--)
	{
		dp[i] = dp[Next[i][0]+1]+1;
		for(int j=1;j<26;j++)
			dp[i] = min (dp[i], dp[Next[i][j]+1]+1);
	}
	int flag=0;
	while(dp[flag])
	{
		for(int i=0;i<26;i++)
		{
			if(dp[flag]==dp[Next[flag][i]+1]+1)
			{
				printf("%c",'a'+i);
				flag=Next[flag][i]+1;
				break;
			}
		}
	}
	printf("\n");
}
	return 0;

}