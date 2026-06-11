#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200010];
signed main()
{
	ios::sync_with_stdio(0);
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];a[i]+=a[i-1];
	}
	int ans=1e18;
	for(int i=1;i<n;i++)ans=min(ans,abs(a[i]-a[n]+a[i]));
	cout<<ans<<endl;
}