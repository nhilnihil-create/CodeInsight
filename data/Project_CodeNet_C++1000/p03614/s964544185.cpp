#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1e5+5;
int a[maxn]={0};
int main()
{
	int n,t=1,k=0;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		if(a[i]==i)
		{
			int t=a[i];a[i]=a[i+1];a[i+1]=t;
			k++;			
		}

			
	}
	cout<<k;
}