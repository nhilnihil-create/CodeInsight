#include<bits/stdc++.h>
using namespace std;
long long n,ans,a[100010];
int main()
{
	cin>>n;
	for(int  i=1;i<=n;i++ ) scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)
    {
    	ans+=a[i]/2;
		a[i]%=2;
		if(i<n&&a[i]&&a[i+1])
		{
			a[i]--;
			a[i+1]--;
			ans++;
		 } 
	}
	cout<<ans<<"\n";
	return 0;
 } 