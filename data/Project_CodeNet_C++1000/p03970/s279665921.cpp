#include<bits/stdc++.h>
using namespace std;
int main()
{
	int ans=0;
	string s,num="CODEFESTIVAL2016";
	cin>>s;
	for(int i=0;i<=s.size();i++)
		if(s[i]!=num[i])ans++;
	cout<<ans<<endl;
}
