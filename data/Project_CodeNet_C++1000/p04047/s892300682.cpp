#include<bits/stdc++.h>
using namespace std;
signed main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	int n,ans=0;
	cin>>n;
	vector<int>a(2*n);
	for(int i=0;i<n*2;i++)cin>>a[i];
	sort(a.begin(),a.end());
	for(int i=0;i<n*2-1;i+=2)
	ans+=a[i];
	cout<<ans<<endl;
    return 0;
}
