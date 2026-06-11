#include<iostream>
using namespace std;
string s;
int dp[2<<17][26];
main()
{
	cin>>s;
	for(int i=s.size();i--;)
	{
		int m=1e9;
		for(int j=0;j<26;j++)
		{
			if(m>dp[i+1][j])m=dp[i+1][j];
			dp[i][j]=dp[i+1][j];
		}
		dp[i][s[i]-'a']=m+1;
	}
	string ans="";
	int id=0;
	while(id<s.size())
	{
		int mi=0;
		for(int i=0;i<26;i++)if(dp[id][i]<dp[id][mi])mi=i;
		char c=mi+'a';
		ans+=c;
		while(id<s.size()&&s[id]!=c)id++;
		id++;
	}
	cout<<ans<<endl;
}