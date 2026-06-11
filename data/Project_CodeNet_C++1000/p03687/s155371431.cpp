#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int main()
{
	string s;
	cin>>s;
	int ans=1e9;
	for(int j=0;j<26;j++)
	{
		int cur=0;
		int pre=-1;
		for(int i=0;i<s.length();i++)
		{
			if(s[i]-'a'==j)
			{
				cur=max(cur,i-pre-1);
				pre=i;
			}
		}
		cur=max(cur,(int)s.length()-pre-1);
		ans=min(ans,cur);
	}
	cout<<ans<<'\n';
}
