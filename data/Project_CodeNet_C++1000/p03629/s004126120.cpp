#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmin(T &x,const T &y)
{
	if(x>y)x=y;
}
const int N=2e5+5;
char s[N];
int nex[N][26],dp[N];

void write(int i)
{
	if(!i)return ;
	int j=0;
	while(dp[nex[i][j]]!=dp[i]-1)++j;
	putchar('a'+j);
	write(nex[i][j]);
}

int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	dp[0]=-1;
	for(int i=n;i;--i)
	{
		for(int j=0;j<26;++j)nex[i][j]=nex[i+1][j];
		nex[i][s[i]-'a']=i+1;
		int mn=dp[nex[i][0]];
		for(int j=1;j<26;++j)chmin(mn,dp[nex[i][j]]);
		dp[i]=mn+1;
	}
	write(1);
}