#include <cstdio> 
#include <cstring>
#include <iostream>
using namespace std;
int l;
char s[100001],c[100001];
int main()
{
	cin>>s;
	l=strlen(s);
	for(int i=0;i<l;i++)
	{
		c[i]=s[l-i-1];
		if(c[i]=='q') c[i]='p';
		else if(c[i]=='p') c[i]='q';
		else if(c[i]=='b') c[i]='d';
		else if(c[i]=='d') c[i]='b';
		if(c[i]!=s[i])
		{
			cout<<"No";break;
		}
		if(i==l-1) cout<<"Yes";
	}
	return 0;
}