#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
 
#define FS              ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll              long long int
#define ld              long double
#define pb              push_back
#define bp              __builtin_popcount
#define sz              size()
#define ff              first
#define ss              second
#define vll             vector<ll>
#define vbool           vector<bool>
#define vpll            vector<pair<ll,ll>>
#define pll             pair<ll,ll>
#define vllv            vector<vector<ll>>
#define setpri(x)       cout<<setprecision(x)<<fixed;
#define all(v)          v.begin(),v.end()
#define allr(v)         v.rbegin(),v.rend()
#define yesr {cout<<"YES"<<endl;return;}
#define nor {cout<<"NO"<<endl;return;}
// getline (std::cin,name);
ll MOD=1e9+7;
ll ceil1(ll n,ll x){return (n-1)/x+(n>0);}

ll gcd(ll a,ll b){return __gcd(a,b);}
ll lcm(ll a,ll b){return (max(a,b)/gcd(a,b))*min(a,b);}

ll pow1(ll n,ll m ,ll mod=MOD );
ll pow2(ll n,ll k);

ll modinv(ll n,ll mod=MOD){  return pow1(n,mod-2,mod);}

bool func(pair<ll,ll> &a,pair<ll,ll> &b ){
        if(a.ff != b.ff)return a.ff < b.ff;
        return a.ss > b.ss;
}

ll const N=(ll)3e2+11;
ll const LG=(ll)log2(N)+1;

vpll v[N];
bool vis[N];
ll dis[N][N];
void disk(ll p,ll n){
        ll pp=p;
        ll dis1[N];
        for(int i=1;i<=n;i++){
                vis[i]=0;
                dis1[i]=1e9;
        }
        priority_queue<pll,vpll,greater<pll>> q;
        
        q.push({0,p});
        dis1[p]=0;
        
        while(!q.empty()){
                ll p=q.top().ss;
                q.pop();
                if(vis[p])continue;
                vis[p]=1;
                
                for(auto x: v[p]){
                        ll node=x.ff;
                        ll w=x.ss;
                        
                        if(dis1[node]>dis1[p]+w){
                                dis1[node]=dis1[p]+w;
                                q.push({dis1[node],node});
                                
                        }
                }
        }
        for(int i=1;i<=n;i++){
                dis[pp][i]=dis1[i];
        }
        
}
void solve(){
        ll i,j,k,l,n,m,x,y,z,r;
        
        cin>>n>>m;
        
        vector<pair<pll,ll>> edge(m);
        for(i=0;i<m;i++){
                cin>>x>>y>>z;
                edge[i]={{x,y},z};
                v[x].pb({y,z});
                v[y].pb({x,z});
        }
        
        for(i=1;i<=n;i++){
                disk(i,n);
        }
        vbool vis1(m);
        
        for(i=0;i<m;i++){
                 x=edge[i].ff.ff;
                y=edge[i].ff.ss;
                z=edge[i].ss;
                
                for(j=1;j<=n;j++){
                        for(k=j+1;k<=n;k++){
                               
                                if(dis[j][x]+z+dis[y][k]==dis[j][k] || dis[j][y]+z+dis[x][k]==dis[j][k])
                                        vis1[i]=1;
                        }
                }
        }
        ll ans=m;
        for(i=0;i<m;i++){
                if(vis1[i])ans--;
        }
        cout<<ans<<endl;
        
        
        
        
        
        
}       
int main(){
        FS;
        
        ll i,j,k,n,m,x,y,z,q;
        q=1;
        // cin>>q;
        for(ll tc=1;tc<=q;tc++){
                // cout<<"Case #"<<tc<<": ";
                solve();
        }
        return 0;
}


ll pow1(ll n,ll m,ll mod){
        if(m==0)return 1;
        
        if(m%2==0)return pow1((n*n)%mod,m/2,mod);
    	
    	return (pow1((n*n)%mod,m/2,mod)*n)%mod;
}

ll pow2(ll n,ll k){
        ll ans=1;
            while(k>0){
                if(k%2==1)ans=ans*n;
                n=n*n;
                k/=2;
            }
            return ans;
}
