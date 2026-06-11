#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	long long mn=1LL<<62;
	for(int i=-100;i<=100;i++)
	{
		int x=i;
		long long cost=0;
		for(int j=0;j<n;j++)
		{
			cost+=abs(a[j]-x)*abs(a[j]-x);
			
		}
		
		mn=min(mn,cost);
	}
	cout<<mn;
}