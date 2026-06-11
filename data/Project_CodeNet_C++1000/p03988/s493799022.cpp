#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,ans,lenth;
int tree[N],tot[N];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>tree[i];
		lenth=max(lenth,tree[i]);
		tot[tree[i]]++;
	}
	if(lenth%2==1)
	{
		if(tot[lenth/2+1]!=2)
		{
			cout<<"Impossible";
			return 0;
		}
		for(int i=1;i<lenth/2+1;i++)
		{
			if(tot[i])
			{cout<<"Impossible";
			return 0;
			}
		}
		for(int i=lenth;i>lenth/2+1;i--)
		{
			if(tot[i]<2)
			{
				cout<<"Impossible";
				return 0;
			}
		}
		cout<<"Possible";
		return 0;
	}
	else
	{
		if(tot[lenth/2]!=1)
		{
			cout<<"Impossible";
			return 0;
		}
		for(int i=1;i<lenth/2;i++)
		{
			if(tot[i])
			{
				cout<<"Impossible";
				return 0;
			}
		}
		for(int i=lenth;i>lenth/2;i--)
		{
			if(tot[i]<2)
			{
				cout<<"Impossible";
				return 0;
			}
		}
		cout<<"Possible";
		return 0;
	}
}