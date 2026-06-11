#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
	ll n,i,x,y,s=0,q;
	cin>>n;
	ll a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		s=s+a[i];
	}

	cin>>q;
	for(i=0;i<q;i++)
	{
		cin>>x>>y;
		ll f=((s-a[x-1])+y);
		cout<<f<<endl;
	}
	return;
	
}
	
int main()
{
//#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output1.txt", "w", stdout);
//#endif
	ll t=1;
	//cin >> t;
	while (t--)
	{
		solve();
	}
}