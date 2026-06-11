#include<bits/stdc++.h>
//ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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
ll inf=1000000000000000000;
double pi=2*acos(0);
#define rep(i,m,n) for(ll i=m;i<n;i++)
#define rrep(i,n,m) for(ll i=n;i>=m;i--)
int dh[4]={1,-1,0,0};
int dw[4]={0,0,1,-1};
int ddh[8]={-1,-1,-1,0,0,1,1,1};
int ddw[8]={-1,0,1,-1,1,-1,0,1};
ll lmax(ll a,ll b){
    if(a<b)return b;
    else return a;
}
ll lmin(ll a,ll b){
    if(a<b)return a;
    else return b;
}
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
int main(){
  int n,m;cin>>n>>m;
  vector<int> v[n+1];
  rep(i,0,m){
    int a,b;cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  int qq;cin>>qq;
  int t[qq],d[qq],c[qq];
  rep(i,0,qq)cin>>t[i]>>d[i]>>c[i];
  int col[n+1];
  fill(col,col+n+1,0);
  int dp[n+1];
  fill(dp,dp+n+1,-1);
  rrep(i,qq-1,0){
    if(dp[t[i]]>=d[i])continue;
    queue<pii> q;q.push({t[i],d[i]});
    while(q.size()>0){
      pll p=q.front();q.pop();
      int now=p.first,dis=p.second;
      if(col[now]==0)col[now]=c[i];
      dp[now]=dis;
      if(dis==0)continue;
      rep(j,0,v[now].size()){
        int ne=v[now][j];
        if(dp[ne]>=dis-1)continue;
        q.push({ne,dis-1});
      }
    }
  }
  rep(i,1,n+1)cout<<col[i]<<endl;
}