#include<bits/stdc++.h>
using namespace std;
string s,t;
int main(void)
{
	cin>>t;
	s=t;
	reverse(s.begin(),s.end());
	for(int i=0;i<s.size();i++)
	{
		(s[i]=='b'?s[i]='d':(s[i]=='d'?s[i]='b':(s[i]=='q'?s[i]='p':s[i]='q')));
	}
	if(s==t)
	{
		puts("Yes");
	}
	else
	{
		puts("No");
	}
	return 0;
}