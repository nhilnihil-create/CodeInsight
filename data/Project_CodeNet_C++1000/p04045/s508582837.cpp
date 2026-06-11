#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	int d[10]={0};
	for(int i=0;i<k;i++)
	{
		int a;
		cin>>a;
		d[a]=1;
	}
	int t=n;
	while(true)
	{
		int temp=t,flag=0;
		while(temp!=0)
		{
			int di=temp%10;
			for(int i=0;i<10;i++)
			{
				if(d[di]==1)
				{
					flag=1;
					break;
				}
			}
			if(flag==1)
			{
				break;
			}
			temp=temp/10;
		}
		if(flag==0)
		{
			break;
		}
		t++;
	}
	cout<<t;
}