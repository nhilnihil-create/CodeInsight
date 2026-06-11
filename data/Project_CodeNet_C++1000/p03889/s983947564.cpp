#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s,s1,s2;
	cin>>s;
	s1=s2=s;
	reverse(s1.begin(),s1.end());
	for (auto &i : s1)
	{
		if (i=='b')
			i='d';
		else
		if (i=='d')
			i='b';
		else
		if (i=='p')
			i='q';
		else
		if (i=='q')
			i='p';
	}
		
	if (s==s1)
	{
		cout<<"Yes";
	}
	else
		cout<<"No";
	return 0;
}