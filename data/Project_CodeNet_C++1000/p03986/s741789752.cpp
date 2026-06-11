#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
long long ans;
string str;
int main()
{
	ios::sync_with_stdio(false);
	cin>>str;
	for(int i=0;i<str.size();)
	{
		if(str[i]=='S'&&str[i+1]=='T')
		{
			str.erase(i,2);
			if(i!=0)
				i--;
		}
		else	i++;
	}
	ans=str.size();
	printf("%lld",ans); 
	return 0;
}