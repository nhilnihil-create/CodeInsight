// luogu-judger-enable-o2
#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s,s1,s2;
	getline(cin,s1);
	s=s1;
	reverse(s.begin(),s.end());
	for(int i=0;i<=s.length()-1;i++)
	{
		if(s[i]=='b') s[i]='d';
		else if(s[i]=='d') s[i]='b';
		else if(s[i]=='p') s[i]='q';
		else if(s[i]=='q') s[i]='p';
	} 
	s2=s;
	if(s2==s1)
	{
		cout<<"Yes"<<endl;
	}
	else cout<<"No"<<endl;
	return 0;
}