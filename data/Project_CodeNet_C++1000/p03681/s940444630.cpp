#include<bits/stdc++.h>
using namespace std;


#define ll long long int
ll fact(ll n){ll res = 1;for (ll i = 2; i <= n; i++)res = res * i,res%=1000000007; 
    return res; } 
 

int main()
{
    ll n,m;
    cin>>n>>m;
    
    if(max(n,m)-min(n,m)>=2)
		cout<<0;
	else
	{
		if(n==m)
		{
		    ll x=fact(n);
		    ll ans=(x*x*2)%1000000007;
		    cout<<ans;
		}
		else
		{
		    cout<<(fact(n)*fact(m))%1000000007;
		}
	}
	return 0;
    // cout<<(fact(100000)*fact(100000)*2)%1000000007;
}