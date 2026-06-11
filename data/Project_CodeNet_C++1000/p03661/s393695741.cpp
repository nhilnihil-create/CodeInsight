#include<bits/stdc++.h>
#define Ll long long
using namespace std;
const Ll N=2e5+5;
Ll a[N];
Ll n,m,ans=1e18,x,y;
int main()
{
	cin>>n;
	for(Ll i=1;i<=n;i++)cin>>a[i],x+=a[i];
	for(Ll i=1;i<n;i++){
		y+=a[i];
		ans=min(ans,abs(x-y-y));
	}
	cout<<ans;
}