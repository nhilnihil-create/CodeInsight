#include<iostream>
#include<algorithm>
using namespace std;
string s;
int nxt[26][2<<17];
int dp[26][2<<17];
bool ap[26];
main()
{
	cin>>s;
	for(int i=0;i<26;i++)nxt[i][s.size()]=s.size();
	for(int i=s.size();i--;)
	{
		for(int j=0;j<26;j++)dp[j][i]=dp[j][i+1],nxt[j][i]=nxt[j][i+1];
		int tmp=s[i]-'a';
		int mi=0;
		for(int j=0;j<26;j++)
		{
			if(dp[mi][nxt[mi][i]]>dp[j][nxt[j][i]])mi=j;
			//if(nxt[mi][i]>nxt[j][i])mi=j;
		}
		dp[tmp][i]=dp[mi][nxt[mi][i]]+1;
		nxt[tmp][i]=i;
	}
	string ans="";
	int id=0;
	while(id<s.size())
	{
		int mi=0;
		for(int i=0;i<26;i++)
		{
			if(dp[mi][nxt[mi][id]]>dp[i][nxt[i][id]])mi=i;
		}
		ans+=mi+'a';
		id=nxt[mi][id]+1;
	}
	cout<<ans<<endl;
}
