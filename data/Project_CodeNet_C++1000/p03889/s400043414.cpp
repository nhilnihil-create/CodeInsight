#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s1,s2;
	cin>>s1;
	s2=s1;
	for(int i=0;i<s2.length();i++)
	{
		if(s2[i]=='b')s2[i]='d';
		else if(s2[i]=='q')s2[i]='p';
		else if(s2[i]=='d')s2[i]='b';
		else if(s2[i]=='p')s2[i]='q';
	}
	reverse(s2.begin(),s2.end());
	if(s1==s2)cout<<"Yes\n";
	else cout<<"No\n";
}