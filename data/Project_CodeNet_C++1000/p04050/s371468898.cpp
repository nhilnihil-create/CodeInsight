#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<ctime>
#include<algorithm>
using namespace std;

int n,m,odd;
int a[101000];

int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
		if(a[i]&1)
		{
			odd++;
		}
	}
	if(odd>2)
	{
		cout<<"Impossible"<<endl;
		return 0;
	}
	if(m==1)
	{
		if(n==1)
			cout<<1<<endl<<1<<endl<<1<<endl;
		else
			cout<<n<<endl<<2<<endl<<1<<" "<<n-1<<endl;
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		if(a[i]&1)
		{
			swap(a[1],a[i]);
			break;
		}
	}
	for(int i=2;i<=m;i++)
	{
		if(a[i]&1)
		{
			swap(a[m],a[i]);
			break;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	if(a[1]==1)
		cout<<m-1<<endl;
	else
		cout<<m<<endl<<a[1]-1<<" ";
	for(int i=2;i<m;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<a[m]+1<<endl;
	return 0;
}
