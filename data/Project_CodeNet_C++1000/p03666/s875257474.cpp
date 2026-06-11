#include <bits/stdc++.h>
#define int long long
#define iris 19260817
using namespace std;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,a,b,c,d,l,r,i;
	cin>>n>>a>>b>>c>>d;
	l=r=a;
	for(i=2;i<=n;i++)
	{
		if(b*2<l+r)
		{
			l-=d;
			r-=c;
		}
		else
		{
			r+=d;
			l+=c;
		}
	}
	if(l<=b && b<=r)
		cout<<"YES\n";
	else
		cout<<"NO\n";
	
	return 0;
}
