#include<iostream>
using namespace std;
int main()
{
	string s;
	cin>>s;
	string tmp=s;
	for(int i=0;i<=s.size()/2-1;i++)
	{
		swap(s[i],s[s.size()-1-i]);
	}
	for(int i=0;i<=s.size()-1;i++)
	{
		if(s[i]=='b')
		{
			s[i]='d';continue;
		}
		if(s[i]=='d')
		{
			s[i]='b';continue;
		}
		if(s[i]=='q')
		{
			s[i]='p';continue;
		}
		if(s[i]=='p')
		{
			s[i]='q';continue;
		}
	}
	if(s==tmp)
	{
		cout<<"Yes"<<endl;
	}
	else
	{
		cout<<"No"<<endl;
	}
	return 0;
}