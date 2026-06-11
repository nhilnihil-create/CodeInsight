#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
string s;
int main()
{
	cin>>s;
	int l=s.size();
	if(s.size()%2)
	{
		printf("No");
		return 0;
	}
	for(int i=0;i<l/2-1;i++)
	{
		if(s[i]=='b')
			if(s[l-i-1]!='d')
			{
				printf("No");
				return 0;
			}
		if(s[i]=='p')
			if(s[l-i-1]!='q')
			{
				printf("No");
				return 0;
			}
		if(s[i]=='d')
			if(s[l-i-1]!='b')
			{
				printf("No");
				return 0;
			}
		if(s[i]=='q')
			if(s[l-i-1]!='p')
			{
				printf("No");
				return 0;
			}
	}
	printf("Yes");
	return 0;
}