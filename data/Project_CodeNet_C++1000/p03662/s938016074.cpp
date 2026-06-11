#include<bits/stdc++.h>
//ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
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
ll mod=1000000007;
ll mod2=998244353;
ll mod3=1000003;
ll mod4=998244853;
ll inf=1LL<<60;
long double pi=3.14159265358979323846L;
double eps=1e-12;
#define rep(i,m,n) for(ll i=m;i<n;i++)
#define rrep(i,n,m) for(ll i=n;i>=m;i--)
#define srep(itr,st) for(auto itr=st.begin();itr!=st.end();itr++)
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
    queue<int> q;
    q.push(1);
    v[1].push_back(0);
    int dis[n+1];
    dis[1]=0;
    while(q.size()>0){
        int now=q.front();q.pop();
        rep(i,0,v[now].size()){
            int ne=v[now][i];
            if(ne==par[now])continue;
            par[ne]=now;
            q.push(ne);
            dis[ne]=dis[now]+1;
        }
    }
    int dp[n+1];
    fill(dp,dp+n+1,0);
    rep(i,1,n+1){
        if(v[i].size()==1)q.push(i);
    }
    int cnt[n+1];
    fill(cnt,cnt+n+1,0);
    while(q.size()>0){
        int now=q.front();q.pop();
        dp[now]++;
        if(now==1)break;
        int pp=par[now];
        cnt[pp]++;
        dp[pp]+=dp[now];
        if(cnt[pp]==v[pp].size()-1)q.push(pp);
    }
    int kai=(dis[n]-1)/2;
    int now=n;
    rep(i,0,kai)now=par[now];
    int wh=dp[now];
    //cout<<now<<endl;
    int bl=n-wh;
    if(wh>=bl)cout<<"Snuke"<<endl;
    else cout<<"Fennec"<<endl;
}

