#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include <boost/multiprecision/cpp_int.hpp>
//typedef boost::multiprecision::cpp_int ll;
typedef long double dd;
#define i_7 (ll)(1E9+7)
//#define i_7 998244353
#define i_5 i_7-2
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    return c+i_7;
}
typedef pair<ll,ll> l_l;
ll inf=(ll)1E16;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
dd EPS=1E-9;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
////////////////////////////

struct edge{ ll to,cost,flag; };
bool used[500010];
ll V;
vector<edge> G[500010];
ll d[500010];

void dijkstra(ll s){
    fill(d,d+V+1,inf);
    d[s]=0;
    priority_queue<pair<ll,l_l>,vector<pair<ll,l_l>>,greater<pair<ll,l_l>>> que;
    que.push(make_pair(0,l_l(0,s)));
    
    while(!que.empty()){
        pair<ll,l_l> p=que.top();que.pop();
        ll v=p.second.second;
        if(d[v]<p.first)continue;
        used[p.second.first]=true;
        //cout<<p.second.first<<endl;
        rep(i,0,G[v].size()-1){
            edge e=G[v][i];
            if(d[e.to]>d[v]+e.cost){
                d[e.to]=d[v]+e.cost;
                que.push(make_pair(d[e.to],l_l(e.flag,e.to)));
            }
        }
    }
    
}


int main(){
    ll n;cin>>n;
    ll m;cin>>m;
    ll a[m],b[m],c[m];
    V=m;
    rep(i,1,m){
        cin>>a[i]>>b[i]>>c[i];
        edge e;
        e.to=b[i];e.cost=c[i];e.flag=i;
        G[a[i]].pb(e);
        e.to=a[i];e.cost=c[i];e.flag=i;
        G[b[i]].pb(e);
    }
    rep(i,1,n){
        dijkstra(i);
    }
    ll ans=0;
    rep(i,1,m){
        if(!used[i])ans++;
    }
    cout<<ans<<endl;
    
    return 0;
}
