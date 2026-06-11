#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
#define LL long long
#define R register
char s[100005],p[100005];
int main()
{
	cin>>s;
	int len=strlen(s);
	for(R int i=0;i<len;i++)p[i]=s[i];
	for(R int i=0;i<len/2;i++)swap(s[i],s[len-i-1]);
	for(R int i=0;i<len;i++)
	{
		if(s[i]=='b')s[i]='d';
		else if(s[i]=='d')s[i]='b';
		else if(s[i]=='p')s[i]='q';
		else if(s[i]=='q')s[i]='p';
		if(s[i]!=p[i])
		{
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	return 0;
}