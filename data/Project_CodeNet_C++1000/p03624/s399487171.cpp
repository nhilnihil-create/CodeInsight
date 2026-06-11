#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	char c='a',d;
	cin>>s;
	int a,i,j;
	a=s.size();
	for(j=0;j<26;j++)
	{
		d=c;	
		for(i=0;i<a;i++)
		{
			if(s[i]==c)
			{
				c++;
				break;
			}
		}
		if(d==c)
		{
			cout<<c<<endl;
			return 0;
		}
	}
	cout<<"None"<<endl;
}