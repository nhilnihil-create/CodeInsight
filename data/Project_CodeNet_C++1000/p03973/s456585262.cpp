#include<bits/stdc++.h>
using namespace std;
long long a[200000];
int main()
{
	long long n;
	cin>>n;	

	for (long long i = 0; i < n; ++i)
	{
		cin>>a[i];
	}

	long long k = 1,ans=0,mx=0;

	for (long long i = 0; i < n; ++i)
	{

		if(a[i]<=k)
		{
			if(a[i]>mx)
			{
				mx = a[i];
			}
			k = mx + 1;
			continue;
		}

		// printf("Customer #%d --> %d %d\n",i+1,a[i],k );
		if(a[i]%k==0)
		{
			ans += a[i]/k - 1;
			a[i] = 1;
		}
		else
		{
			ans += a[i]/k;
			a[i] = a[i]%k;
		}

		if(a[i]>mx)
		{
			mx = a[i];
		}
		k = mx + 1;
		// printf("Ans : %d\n",ans );
	}
	cout<<ans<<endl;
	
	return 0;
}