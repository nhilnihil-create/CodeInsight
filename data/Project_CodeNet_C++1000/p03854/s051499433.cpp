#include<bits/stdc++.h>
using namespace std;
int main()
{
	
	string s;
	cin >> s;
	deque<char>c;
	for(int i=0;i<s.length();i++)
	{
		c.push_back(s[i]);
	}
	bool flag = true;
	string s1 = "maerd",s2 = "remaerd",s3 = "esare",s4 = "resare";
	while(!c.empty())
	{
		string loc;
		while(!c.empty()&&loc.length()!=5)
		{
			loc = loc+c.back();
			c.pop_back();
		}
		if(loc==s1||loc==s3)
		{
			continue;
		}
		else
		{
			while(!c.empty()&&loc.length()!=6)
			{
				loc = loc+c.back();
				c.pop_back();
			}
			if(loc==s4)
			{
				continue;
			}
			else
			{
				while(!c.empty()&&loc.length()!=7)
				{
					loc = loc+c.back();
					c.pop_back();
				}
				if(loc==s2)
				{
					continue;
				}
				else
				{
					flag = false;
					break;
				}
			}
		}
	}
	if(flag)
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
	}
	return 0;
}
	
