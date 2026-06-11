#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
char s[100005],s1[100005];
int main()
{
	cin>>s;
	int len=strlen(s),m=-1;
	for(int i=len-1;i>=0;i--)
	{
		s1[++m]=s[i];
		if(s1[m]=='b')s1[m]='d';
		else if(s1[m]=='d')s1[m]='b';
		else if(s1[m]=='p')s1[m]='q';
		else if(s1[m]=='q')s1[m]='p';
	}
	int p=1;
	for(int i=0;i<len;i++)
	{
		if(s[i]!=s1[i])p=0;
	}
	if(p)printf("Yes");
	else printf("No");
	//printf("%c%c%c%c",s1[0],s1[1],s1[2],s1[3]);
	
	
	
	return 0;
}