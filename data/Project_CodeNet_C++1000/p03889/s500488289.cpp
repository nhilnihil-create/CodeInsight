#include<bits/stdc++.h>
using namespace std;
bool ismirror(string s)
{
	string ss;
	int len = s.size();
	for(int i = 0;i < len;i++)
	{
		ss += ' ';
	}
	int h = 0;
	for(int i = len-1;i >= 0;i--)
	{
		ss[h++] = s[i];
	}
	for(int i = 0;i < len;i++)
	{
		if(ss[i] == 'b')
		{
			ss[i] = 'd';
			continue;
		}else if(ss[i] == 'd')
		{
			ss[i] = 'b';
			continue;
		}else if(ss[i] == 'p')
		{
			ss[i] ='q';
			continue;
		}else if(ss[i] == 'q')
		{
			ss[i] = 'p';
			continue;
		}
	}
	if(ss == s)
	{
		return true;
	}else
	{
		return false;
	}
}
int main()
{
	string s;
	cin>>s;
	if(ismirror(s))
	{
		cout<<"Yes";
	}else cout<<"No";
	return 0;
	
}