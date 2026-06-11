#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
	int l,i,j;
	cin>>s;
	l=s.size();
	if(l%2)
	{
		cout<<"No";
		return 0;
	}
	for(i=0,j=l-1;i<j;i++,j--)
	{
		if(s[i]=='b'&&s[j]!='d')
		{
			cout<<"No";
			return 0;
		}
		else
		{
			if(s[i]=='d'&&s[j]!='b')
			{
				cout<<"No";
				return 0;
			}
			else
			{
				if(s[i]=='p'&&s[j]!='q')
				{
					cout<<"No";
					return 0;
				}
				else
				{
					if(s[i]=='q'&&s[j]!='p')
					{
						cout<<"No";
						return 0;
					}
				}
			}
		}
	}
	cout<<"Yes";
	return 0;
}