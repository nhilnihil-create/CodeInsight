#include<bits/stdc++.h>
using namespace std;
int main()
{
	char a[233333];
	gets(a);
	int len=strlen(a),b=-1;
	while(len)
	{
		len--;
		b++;
		if(a[len]=='b')
		{
			if(a[b]!='d')
			{
				cout<<"No";
				return 0;
			}
		}
		if(a[len]=='d')
		{
			if(a[b]!='b')
			{
				cout<<"No";
				return 0;
			}
		}
		if(a[len]=='p')
		{
			if(a[b]!='q')
			{
				cout<<"No";
				return 0;
			}
		}
		if(a[len]=='q')
		{
			if(a[b]!='p')
			{
			    cout<<"No";
			    return 0;
			}
		}
	}
	cout<<"Yes";
	return 0;
}
