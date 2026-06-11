#include<bits/stdc++.h>
using namespace std;
int n,a[101010],b[101010];
string s;
bool check(int x,int y)
{
	a[0]=x;
	a[1]=y;
	for(int i=1;i<n;i++)
	{
		a[i+1]=b[i]*a[i-1]*a[i];
	}
	if(a[n]==a[0] && a[1]==b[0]*a[n-1]*a[0])
	{
		for(int i=0;i<n;i++)
		{
			if(a[i]==1)
			{
				cout<<'S';
			}
			else
			{
				cout<<'W';
			}
		}
		return true;
	}
	return false;
}
int main()
{
	cin>>n>>s;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='o')
		{
			b[i]=1;
		}
		else
		{
			b[i]=-1;
		}
	}
	if(check(1,1))
	{
		return 0;
	}
	if(check(1,-1))
	{
		return 0;
	}
	if(check(-1,1))
	{
		return 0;
	}
	if(check(-1,-1))
	{
		return 0;
	}
	cout<<-1<<endl;
	return 0;
}