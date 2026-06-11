#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
int main()
{
	int n;
	int a[100010];
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int d=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==i)
		{
			if(i==n)
			{
				int t=a[i];
				a[i]=a[i-1];
				a[i-1]=t;
				d++;
			}
			else
			{
				int t=a[i];
				a[i]=a[i+1];
				a[i+1]=t;
				d++;
			}

		}
	}
	cout<<d<<endl;
	return 0;
}