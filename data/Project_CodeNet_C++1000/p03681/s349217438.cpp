#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define bg begin()
#define end end()
#define sz size()
#define vi vector<int>
#define vl vector<long long int>
#define mod 1000000007
int main(){
	fast;
	int n,m;
	ll ans=1;
	cin>>n>>m;
	if(abs(n-m)>1)
	{
		cout<<"0";
		return 0;
	}
	if(n==m)
		ans=2;
	while(n+m>2)
	{
		ans=ans*n%mod;
		ans=ans*m%mod;
		n=(n)?n-1:n;
		m=(m)?m-1:m;
		if(ans==0)
		    break;
	}
	cout<<ans;
	return 0;
}

