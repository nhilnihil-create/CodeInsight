#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	char s[100100];
	scanf("%s",s);
	int l=strlen(s);
	if(l%2!=0)
	{
		cout<<"No\n";
		return 0;
	}
	bool f=0;
	for(int i=0;i<l/2;i++)
	{
		if(s[i]=='p'&&s[l-i-1]!='q')
		{
			f=1;break;
		}
		if(s[i]=='q'&&s[l-i-1]!='p')
		{
			f=1;break;
		}
		if(s[i]=='b'&&s[l-i-1]!='d')
		{
			f=1;break;
		}
		if(s[i]=='d'&&s[l-i-1]!='b')
		{
			f=1;break;
		}
	}
	if(!f)
	cout<<"Yes\n";
	else
	cout<<"No\n";
	return 0;
}