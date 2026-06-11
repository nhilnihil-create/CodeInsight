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

ll dif(ll a,ll b)
{
ll ans=0ll;	
  while(a>0 || b>0)
  {
	  ll r1 = (a&1);
	  ll r2 = (b&1);
	  if(r1!=r2)
	  {
		ans++;  
	   }
	  a = a>>1;
	  b = b>>1;
  }
	
	
	return ans;
}



ll calc(ll n)
{
if(n==0)
{
return 0;	
}
if(n==1)
{
return 1;	
}	
ll p = n/2;
ll ans = calc(p) + n;

return ans;	
}


void solve()
{
	ll n;
	cin>>n;
	ll a[n+5];
	ll md =0;
	for(ll i=0;i<n;i++)
	{
	cin>>a[i];	
	md+=a[i];
	}
	ll c =0;
	if(md%n!=0)
	{
	c=1;	
	}
	md /= n;
	
	md+=c;
	ll ans1=0;
	ll md1=md-c;
	ll ans =0;
	
	for(ll i=0;i<n;i++)
	{
	ans += ((md-a[i])*(md-a[i]));	
	ans1 +=((md1-a[i])*(md1-a[i]));
	}
	ans = min(ans,ans1);
	cout<<ans<<endl;
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
