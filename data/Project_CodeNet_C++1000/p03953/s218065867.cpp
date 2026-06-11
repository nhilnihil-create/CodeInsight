#include<iostream>
using namespace std;
int n,m;long k;
int x[1<<17],d[1<<17];
int t[1<<17],s[1<<17],b[1<<17];
main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x[i];
		if(i)d[i-1]=x[i]-x[i-1];
	}
	for(int i=0;i<n-1;i++)s[i]=t[i]=i;
	cin>>m>>k;
	for(int i=0;i<m;i++)
	{
		int a;cin>>a;
		t[a-2]^=t[a-1]^=t[a-2]^=t[a-1];
	}
	while(k)
	{
		if(k&1)
		{
			for(int i=0;i<n-1;i++)s[i]=t[s[i]];
		}
		for(int i=0;i<n-1;i++)b[i]=t[t[i]];
		for(int i=0;i<n-1;i++)t[i]=b[i];
		k>>=1;
	}
	long now=x[0];
	cout<<now<<endl;
	for(int i=0;i<n-1;i++)
	{
		now+=d[s[i]];
		cout<<now<<endl;
	}
}