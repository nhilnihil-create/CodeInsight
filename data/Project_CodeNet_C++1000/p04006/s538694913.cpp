#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[2333],b[2333];
long long ans=0x3f3f3f3f3f3f3f3fll,sum;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i],b[i]=0x3f3f3f3f;
	for(int s=0;s<=n;s++)
	{
		sum=1ll*s*k;
		for(int i=1;i<=n;i++)
		{
			b[i]=min(b[i],a[(i-s+n-1)%n+1]);
			sum+=b[i];
		}
		ans=min(ans,sum);
	}
	cout<<ans<<endl;
	return 0;
}