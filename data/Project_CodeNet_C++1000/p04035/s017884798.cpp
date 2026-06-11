#include<bits/stdc++.h>
#define ll long long int
#define mk make_pair
#define pb push_back
#define INF (ll)1e18
#define pii pair<ll,ll>
#define mod 1000000007 //998244353
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fb(i,a,b) for(ll i=a;i>b;i--)
#define ff first
#define ss second
#define srt(v)  if(!v.empty())sort(v.begin(),v.end())
#define PI 3.141592653589793238
#define pq priority_queue<ll>
#define pqr priority_queue<ll,vector<ll>,greater<ll>()>
using namespace std;
ll pow_mod(ll a,ll b)
{
	ll res=1;
	while(b!=0)
	{
		if(b&1)
		{
			res=(res*a)%mod;
		}
		a=(a*a)%mod;
		b/=2;
	}
	return res;
}
void solve()
{
 ll n,l;
 
 cin>>n>>l;
 
 ll a[n+1];
 
 for(ll i=1;i<=n;i++)
 cin>>a[i];
 
 ll len=0;
 
 for(ll i=1;i<=n;i++)
 len+=a[i];
 
 
 vector<ll>v;
    ll id=-1;
    
    for(ll i=1;i<n;i++){
        if(a[i]+a[i+1]>=l){
            id=i;
            break;
        }
    }
    
    if(id==-1){
        cout<<"Impossible\n";
        return;
    }
    
    cout<<"Possible\n";
    
    for(ll i=1;i<id;i++)
    cout<<i<<"\n";
    
    for(ll i=n-1;i>id;i--)
    cout<<i<<"\n";
    
    cout<<id<<endl;
}
int32_t main()
{    ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);
     
//Start from Here.

  ll t;
  t=1;
 // cin>>t;
  while(t--)
  solve();
  
//Good Bye!
    return 0;
}
