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
   ll n;
   cin>>n;
   
   vector<ll>adj[n+1];
   
   for(ll i=2;i<=n;i++){
       ll x;
       cin>>x;
       adj[x].pb(i);
       adj[i].pb(x);
   }
   
   
   ll sz[n+1]={0};
   
   ll mx=0;
   
   function<void(ll,ll)>dfs=[&](ll s,ll p){
       
       
       vector<ll>v;
       for(auto a:adj[s])
       {
           if(a==p)
           continue;
           
           dfs(a,s);
           v.pb(a);
       }
       
       if(v.empty()){
           if(s==1)
           sz[s]=adj[s].size();
           else
           sz[s]=(ll)adj[s].size()-1;
       }
       
       else{
         vector<pii>p;
          
          for(ll i=0;i<(ll)v.size();i++)
           p.pb(mk(sz[v[i]],v[i]));
           
           sort(p.begin(),p.end(),[&](pii aa,pii bb){
               return aa.ff>bb.ff;
           });
           
           for(ll i=0;i<(ll)p.size();i++){
               
              
               ll node=p[i].ss;
               
               sz[s]=max(sz[s],i+1+sz[node]);
           }
       }
   };
   
   
   dfs(1,-1);
    
    cout<<sz[1]<<endl;
   
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