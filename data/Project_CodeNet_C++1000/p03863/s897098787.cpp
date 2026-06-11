#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

char s[100000+5];

int main()
{
	scanf("%s",s+1);int len=strlen(s+1);
	if(s[1]==s[len] && len%2==1) puts("Second");
	else if(s[1]==s[len] && len%2==0)  puts("First");
	else if(s[1]!=s[len] && len%2==1) puts("First");
	else if(s[1]!=s[len] && len%2==0)puts("Second");
	return 0;
}