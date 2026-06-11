#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1000001],i,j,n,m,sum=0;
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(i=2;i<=n;i++)
	{
		if(a[i]==a[i-1])
		{
			sum++;
		}
	}
	sum=(sum+1)/2*2;
	cout<<n-sum;
	return 0;
}