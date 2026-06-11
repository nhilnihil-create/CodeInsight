#include<bits/stdc++.h>
using namespace std;
char a[100002],c[100002];
int main()
{
	cin>>a;
	int b=strlen(a),d;
	for(int i=0;i<b;i++)
	{
		if(a[i]=='p')
		{
			c[i]='q';
		}
		else if(a[i]=='q')
		{
			c[i]='p';
		}
		else if(a[i]=='b')
		{
			c[i]='d';
		}
		else if(a[i]=='d')
		{
			c[i]='b';
		}
	}
	for(int i=0;i<b;i++)
	{
		d=b-1-i;
		if(a[i]!=c[d])
		{
			cout<<"No"<<endl;return 0;
		}
	}
	cout<<"Yes"<<endl;
	return 0;
}