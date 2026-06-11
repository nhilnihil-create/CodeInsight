#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
char s[100005];
int main()
{
	cin>>s;
	int len=strlen(s);
	if(len%2==1)
	{
		if(s[0]!=s[len-1])printf("First");
		else printf("Second");
	}
	else
	{
		if(s[0]==s[len-1])printf("First");
		else printf("Second");
	}
	
	return 0;
 } 