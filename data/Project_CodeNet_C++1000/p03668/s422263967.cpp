#include<bits/stdc++.h>
//ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//clock_t start=clock();clock_t end=clock();cout<<(double)(end-start)/CLOCKS_PER_SEC<<endl;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef pair<int,int> pii;
typedef pair<pii,int> ppii;
typedef pair<int,pii> pipi;
typedef pair<ll,ll> pll;
typedef pair<pll,ll> ppll;
typedef pair<ll,pll> plpl;
typedef tuple<ll,ll,ll> tl;
typedef pair<double,double> pdd;
typedef vector<vector<ll>> mat;
ll mod2=1000000007;
ll mod=998244353;
ll mod3=1000003;
ll mod4=998244853;
ll mod5=1000000009;
ll inf=1LL<<60;
double pi=3.141592653589793238462643383279L;
double eps=1e-14;
#define rep(i,m,n) for(ll i=m;i<n;i++)
#define rrep(i,n,m) for(ll i=n;i>=m;i--)
#define srep(itr,st) for(auto itr=st.begin();itr!=st.end();itr++)
#define mrep(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define Max(a,b) a=max(a,b)
#define Min(a,b) a=min(a,b)
int dh[4]={1,-1,0,0};
int dw[4]={0,0,1,-1};
int ddh[8]={-1,-1,-1,0,0,1,1,1};
int ddw[8]={-1,0,1,-1,1,-1,0,1};
ll gcd(ll a,ll b){
    if(a<b)swap(a,b);
    if(b==0)return a;
    if(a%b==0)return b;
    return gcd(b,a%b);
}
ll lcm(ll a,ll b){
    ll c=gcd(a,b);
    return a*b/c;
}
ll Pow(ll n,ll k){
    ll ret=1;
    ll now=n;
    while(k>0){
        if(k&1)ret*=now;
        now*=now;
        k/=2;
    }
    return ret;
}
ll beki(ll n,ll k,ll md){
  ll ret=1;
  ll now=n;
    now%=md;
  while(k>0){
    if(k%2==1){
      ret*=now;
      ret%=md;
    }
    now*=now;
    now%=md;
    k/=2;
  }
  return ret;
}
ll gyaku(ll n,ll md){
  return beki(n,md-2,md);
}
ll popcount(ll n){
    ll ret=0;
    ll u=n;
    while(u>0){
        ret+=u%2;
        u/=2;
        
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    vector<int> v[n+1];
    rep(i,0,n-1){
        int a,b;cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int par[n+1];
    par[1]=0;
    v[1].push_back(0);
    int cnt[n+1];
    fill(cnt,cnt+n+1,0);
    queue<int> q;
    q.push(1);
    while(q.size()>0){
        int now=q.front();q.pop();
        rep(i,0,v[now].size()){
            int ne=v[now][i];
            if(par[now]==ne)continue;
            par[ne]=now;
            q.push(ne);
        }
    }
    int g[n+1];
    rep(i,1,n+1){
        if(v[i].size()==1)q.push(i);
    }
    while(q.size()>0){
        int now=q.front();
        q.pop();
        g[now]=0;
        rep(i,0,v[now].size()){
            int ne=v[now][i];
            if(par[now]==ne)continue;
            g[now]^=g[ne]+1;
        }
        int p=par[now];
        cnt[p]++;
        if(cnt[p]==v[p].size()-1)q.push(p);
    }
    if(g[1]==0)cout<<"Bob"<<endl;
    else cout<<"Alice"<<endl;
   // rep(i,1,n+1)cout<<g[i]<<endl;
}

