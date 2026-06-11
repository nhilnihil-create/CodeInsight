#include<bits/stdc++.h>
using namespace std;
#define int long long
int a,b,c,d,n;
signed main()
{
	
	cin>>n>>a>>b>>c>>d;n--;
	for(int i=n;i>=0;i--)
	{
		int l=a+i*c-(n-i)*d;int r=a+i*d-(n-i)*c;
		//cout<<l<<" "<<r<<endl;
		if(l>r)swap(l,r);
		if(b<=r&&b>=l)cout<<"YES",exit(0);
	}
	cout<<"NO";
}