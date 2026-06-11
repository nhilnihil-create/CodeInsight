#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int a[5010];
bool b[5010];
int main()
{
	int n,k;
	int sum=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]=min(a[i],k);
		sum+=a[i];
	}
	sort(a+1,a+n+1);
	b[0]=1;
	for(int i=n;i>=0;i--)
	{
		bool f=0;
		for(int j=k-1;j>=k-sum&&j>=0;j--)
			if(b[j])
			{
				f=1;
				break;
			}
		if(!f)
		{
			cout<<i;
			return 0;
		}
		for(int j=k;j>=a[i];j--)
			if(b[j-a[i]]==1)
				b[j]=1;
		sum-=a[i];
	}
	return 0;
}
