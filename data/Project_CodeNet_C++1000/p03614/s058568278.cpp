#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int a[100000];
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==i)
			{
				int t=a[i];a[i]=a[i+1];a[i+1]=t;
				sum++;
			}
		}
		cout<<sum<<"\n";
	}
}