#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll,ll> pairs;
#define mod 1000000007
typedef pair<ll,ll>pairs;
ll ans(ll n)
{
    ll p=1;;
    for(int i=1;i<=n;i++)
    {
        p*=i;
        p%=mod;
    }
    p*=p;
    p%=mod;
    return p;
}
int main() {
	// your code goes here
	std::ios::sync_with_stdio(false);
	ll t,n,i,j,k,l,c,f;
	cin>>i>>j;
	if(llabs(i-j)==1)
	cout<<(ans(min(i,j))*max(i,j))%mod;
	else if(i==j)
	cout<<(ans(i)*2)%mod;
	else
	cout<<0;
	return 0;
}
