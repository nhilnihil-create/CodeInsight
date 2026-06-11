#include<bits/stdc++.h>
using namespace std;
string e,m;
int l;
int main()
{
	cin>>e;
	m=e;
	l=e.length();
	if(l%2==0)
	{
		for(int i=0;i<l/2;i++)//双数长度 
		{
			swap(e[i],e[l-i-1]);
		}
	}
	else
	{
		for(int i=0;i<l/2;i++)//单数长度 
		{
			swap(e[i],e[l-i-1]);
		}
	}
	//改b为d，改d为b，改p为q，改q为p（不要搞错对应关系）
	for(int i=0;i<l;i++)
	{
		switch(e[i])
		{
			case 'b':
			{
				e[i]='d';
				break;
			}
			case 'd':
			{
				e[i]='b';
				break;
			}
			case 'p':
			{
				e[i]='q';
				break;
			}
			case 'q':
			{
				e[i]='p';
				break;
			}
		}
	}
	if(e==m)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
	return 0;
}