#include <bits/stdc++.h>
#include <set>
#define ll long long 
#include <string>
#define pb push_back
#define mp make_pair
# define pi 3.14159265358979323846
#define mod 1000000007
#define rep(i,n) for(i=0;i<n;i++)
#define repk(i,k,n) for(i=k;i<n;i++)
using namespace std;
void fastio()
{
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

}
ll int multiply(ll int a,ll int b)
{
	ll int ans=(a%mod*b%mod)%mod;
	return ans;
}
ll int add(ll int a, ll int b)
{
	ll int ans=(a%mod+b%mod)% mod;
	return ans;
}
ll int l(ll int k)
{
	ll int l=1,r=1e9,ans;
	while(l<=r)
	{
		ll int mid=l+(r-l)/2;
		ll int v=mid*(mid+1)/2;
		if (v>=k)
		{
			ans=mid;
			r=mid-1;
		}
		else
		{
			l=mid+1;
		}
	}
	return ans;

}
 
void solve()
{
	ll int x;cin>>x;
	ll int ans=l(x);
	cout<<ans<<endl;

}

int main()
{ 
	fastio();
    ll int t;
    // cin>>t;
    t=1;
    while(t--)
    {
    	solve();
    }
}

	
		
	
	
	
	



