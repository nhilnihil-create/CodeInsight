#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007

void solve()
{
	ll w,h,n,x,y,a;
	cin>>w>>h>>n;
	ll x1=0,x2=w,y1=0,y2=h;
	
	while(n--)
	{
		cin>>x>>y>>a;
		if(a==1)
			x1=max(x1,x);
		else if(a==2)
			x2=min(x2,x);
		else if(a==3)
			y1=max(y1,y);
		else
			y2=min(y2,y);
	}

	if(x2>x1&&y2>y1)
	cout<<abs((x1-x2)*(y1-y2));
	else
	cout<<0;
	
	return;
}

int main()
{
	fast;
	ll q=1;
	// cin>>q;
	while(q--)
		solve();
	return 0;
}

