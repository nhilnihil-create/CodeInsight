#include<bits/stdc++.h>
using namespace std;
string s1;
int len;
stack<char> x;
int main()
{
	cin>>s1;
	len=s1.size();
	if(len%2!=0)
	{cout<<"No";return 0;}
	for(int i=0;i<=len-1;i++)
	{
		x.push(s1[i]);
	}
	int flag=1;
	for(int i=0;i<=len-1;i++)
	{
		char k=x.top();
		x.pop();
		{
			if(k=='b')
			k='d';
			else
			if(k=='d')
			k='b';
			else if(k=='p')
			k='q';
			else if(k=='q')
			k='p';
			if(k!=s1[i])
			{flag=0;break;}
		}
	}
	if(flag)
	cout<<"Yes";
	else
	cout<<"No";
	return 0;
}