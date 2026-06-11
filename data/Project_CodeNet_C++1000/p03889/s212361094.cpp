#include<bits/stdc++.h>
using namespace std;
char s[100009],st[100009],ss[100009];
int len;
int main()
{
	gets(s);
	len=strlen(s);
	for(int i=0;i<strlen(s);++i)
		st[len-i-1]=s[i];
	for(int i=0;i<strlen(st);++i)
	{
		if(st[i]=='b') ss[i]='d';
		if(st[i]=='d') ss[i]='b';
		if(st[i]=='p') ss[i]='q';
		if(st[i]=='q') ss[i]='p';
	}
	if(strcmp(s,ss)==0) cout<<"Yes";
	else cout<<"No";
	return 0;
}
