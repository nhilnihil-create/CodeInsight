#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007
int main(){
	fast;
	ll x;
	cin>>x;
	if(x<=6)
	{
		cout<<1;
		return 0;
	}
	if(x<=11)
	{
		cout<<2;
		return 0;
	}
	ll ans=x/11;
	ans=2*ans;
	if(x%11<=6&&x%11>0)
		cout<<ans+1;
	else if(x%11>6)
		cout<<ans+2;
	else
		cout<<ans;
		
	return 0;
}

