#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

int main()
{
	string a;
	cin>>a;
	if(a.size()%2!=0)
	{
		printf("No\n");
		return 0;
	}
	for(int i=0;i<=a.size()/2-1;i++)
	{
		if(a[i]=='p'&&a[a.size()-1-i]=='q')continue;
		else if(a[i]=='q'&&a[a.size()-1-i]=='p')continue;
		else if(a[i]=='d'&&a[a.size()-1-i]=='b')continue;
		else if(a[i]=='b'&&a[a.size()-1-i]=='d')continue;
		else
		{
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}