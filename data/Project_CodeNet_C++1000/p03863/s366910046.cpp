#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int len=s.size();
	/*for(int i=0;i<len;i++)
	{
		for(int j=i+1;j<len;j++)
		{
			if(s[j]==s[i])
			{
				n=j-i-1;
				if(n%2==0)
					cout<<"First";
				else
					cout<<"Second";
				return 0;
			}
		}
	}*/
	if(s[0]==s[len-1])
	{
		if(len%2)
			cout<<"Second";
		else
			cout<<"First";
	}
	else
	{
		if(len%2)
			cout<<"First";
		else
			cout<<"Second";
	}
	return 0;
}
//game