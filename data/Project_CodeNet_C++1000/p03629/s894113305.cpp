#include<bits/stdc++.h> 
using namespace std;
int dp[200007],nxtpos[200007],pos[100],c,nxtchr[200007];
string s;
int main()
{
	cin>>s;
	int n=s.length();
	s='.'+s;
	for(int i=0;i<26;i++)
	{
		pos[i]=n+1;
	}
	for(int i=n;i>=0;i--)
	{
		int mn=n+5;
		for(int j=0;j<26;j++)
		{
			if(mn>dp[pos[j]])
			{
				mn=dp[pos[j]];
				c=j;
			}
		}
		dp[i]=dp[pos[c]]+1;
		nxtpos[i]=pos[c];
		nxtchr[i]=c;
		pos[s[i]-'a']=i;
	}
	int x=0;
	while(x<=n)
	{
		cout<<char(nxtchr[x]+'a');
		x=nxtpos[x];
	}
}