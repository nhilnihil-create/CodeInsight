#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll a,b,c,d,e;
	cin>>a>>b>>c>>d>>e;
	b=min(b,2*a);
	c=min(c,2*b);
	d=min(d,2*c);
	e=4*e;
	ll ans=0;
	ans+=(e/8)*d;
	e=e%8;
ll dp[8]={0,a,b,a+b,c,c+a,c+b,c+a+b};
ans+=dp[e];
cout<<ans;
return 0;	
}