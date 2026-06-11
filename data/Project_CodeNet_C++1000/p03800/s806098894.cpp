#include <bits/stdc++.h>
using namespace std;
int animal[100000011];
int main()
{
	int n;
	string s;
	cin >>n>>s;
	s=s+s;
	for(int i=0;i<2;i++)
	for(int j=0;j<2;j++)
	{
		animal[0]=i;
		animal[1]=j;
		for(int l=2;l<n+2;l++)
		{
			if(s[l-1]=='o'&&animal[l-1]==0)
			animal[l]=1-animal[l-2];
			if(s[l-1]=='o'&&animal[l-1]==1)
			animal[l]=animal[l-2];
			if(s[l-1]=='x'&&animal[l-1]==0)
			animal[l]=animal[l-2];
			if(s[l-1]=='x'&&animal[l-1]==1)
			animal[l]=1-animal[l-2];
		}
		if(animal[n]==animal[0]&&animal[n+1]==animal[1])
		{
			for(int i=0;i<n;i++)
			cout <<(animal[i]?"S":"W");
			return 0;
		}
	}
	puts("-1");
	return 0;
}