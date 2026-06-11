#include<bits/stdc++.h>
using namespace std;
char s[100010],ss[100010];
int main()
{
	scanf("%s",s+1);
	int len=strlen(s+1);
	for(int i=1;i<=len;i++)
		ss[i]=s[len-i+1];
	for(int i=1;i<=len;i++)
		if(ss[i]=='b')ss[i]='d';
		else if(ss[i]=='d')ss[i]='b';
		else if(ss[i]=='p')ss[i]='q';
		else if(ss[i]=='q')ss[i]='p';
	for(int i=1;i<=len;i++)
		if(s[i]!=ss[i])return puts("No"),0;
	puts("Yes");
	return 0;
}