#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
bool dp[1000000];
string s;
int main() 
{
	while(cin>>s)
	{
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		for(int i=0;i<s.size();i++)
		{
			if(dp[i]==0)continue;
			if(i+5<=s.size()&&s.substr(i,5)=="dream")dp[i+5]=1;
			if(i+7<=s.size()&&s.substr(i,7)=="dreamer")dp[i+7]=1;
			if(i+5<=s.size()&&s.substr(i,5)=="erase")dp[i+5]=1;
			if(i+6<=s.size()&&s.substr(i,6)=="eraser")dp[i+6]=1;
		}
		if(dp[s.size()]==1)
		cout<<"YES"<<"\n";
		else
		cout<<"NO"<<"\n"; 
	}	
	return 0;
}
