#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[100010],n;
signed main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	int ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]&&a[i-1])a[i]--,ans++;
		ans+=(a[i]>>1);
		a[i]&=1;
	}
	cout<<ans<<endl;
    return 0;
}
