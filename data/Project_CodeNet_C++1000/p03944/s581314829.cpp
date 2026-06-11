#include<bits/stdc++.h>                   // below comment for pbds
#include<ext/pb_ds/assoc_container.hpp>   // to use it make ordered_set
#include<ext/pb_ds/tree_policy.hpp>       // all set fnct + = 1. order_of_key(x); // number of 
#define ll long long                      //element strictly smaller than it;
#define ld long double                    // 2. find_by_order(x),pointer el at x pos after sort  use as s.f();
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;                     
using namespace __gnu_pbds;
// assert(a[i]<n ) // if we want to check for special cond , used for debug
// make less_equal in order to make a multiset pbds
const ll Mod = (int)1e9;
ll CaseN=1;
ll fast_power(ll a,ll b,ll mod){
	ll ans=1;
	while(b>0){
	if(b&1){
	ans=(a*ans)%mod;
	}
	b=b>>1;
	a=(a*a)%mod;
	}
	return ans;
	}


ll nCr(ll n ,ll r)
{
ll p= n;
r = min(r,n-r);
ll a =1;
ll b=1;	
while(r)
{
	a = a*p;
	b = b*r;
	
	ll g = __gcd(a,b);
	
	a = a/g;
	b = b/g;
	
	p--;
	r--;	
}	
return a;
	
}

void solve()
{
	
	ll w,h,n;
	cin>>w>>h>>n;
	ll x[n+4],y[n+4],a[n+4];
	ll ans =0;
	ll a1=0,a2=0,b1=w, b2 =h;
	for(ll i=0;i<n;i++)
	{
	cin>>x[i]>>y[i]>>a[i];
		if(a[i]==1)
		{
			a1=max(x[i],a1);
		}
		else if(a[i]==2)
		{
			b1 = min(x[i],b1);
		}
		else if(a[i]==3)
		{
			a2 = max(y[i],a2);
		}
		else
		{
			b2 = min(y[i],b2);
		}
	}
    if(b1>a1 && b2>a2)
    {
	ans = (b1-a1)*(b2-a2) ;
		
	}
    
	
   cout<<ans<<endl;
	 //if(ans)
  //{
  //cout<<"Yes"<<endl; 
  //}
  //else
   //{
  //cout<<"No"<<endl;
  //}
 
	
    //cout<<"Case #"<<CaseN<<": ";
   CaseN++;
	// print your ans below;
return ;
}


signed main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t=1;
	//cin>>t;
	while(t--)
	{
	solve();	
	}
}
