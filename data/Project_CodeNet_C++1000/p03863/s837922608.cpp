#include<iostream>
using namespace std;
int main()
{
	string s;
	cin>>s;
	if(s[0]==s[s.length()-1])
	{
		if(s.length()%2==1)
		{
			cout<<"Second";
		}else
		{
			cout<<"First";
		}
	}else
	{
		if(s.length()%2==1)
		{
			cout<<"First";
		}else
		{
			cout<<"Second";
		}
	}
	return 0;
}