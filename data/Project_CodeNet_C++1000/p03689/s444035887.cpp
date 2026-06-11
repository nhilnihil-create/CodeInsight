#include<iostream>
#include<algorithm>
#include<cstdio>
#define mx 500
using namespace std;
long long n,m,h,w;
int main()
{
	long long i,j,u,v;
	cin>>n>>m>>h>>w;
	if(n%h==0 && m%w==0)
	{
		cout<<"No"<<endl;
	}
	else
	{
		cout<<"Yes"<<endl;
		u=(h*w-1)*mx+1;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(i%h==0 && j%w==0)
				{
					cout<<-u<<" ";
				}
				else
				{
					cout<<mx<<" ";
				}
			}
			cout<<endl;
		}
	}
	return(0);
}