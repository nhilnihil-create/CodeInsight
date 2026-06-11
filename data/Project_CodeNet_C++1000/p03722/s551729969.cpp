#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
#include <algorithm> 
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define ll long long
#define rep(i,n) for (ll i = 0; i < (n); i++)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define FORR(i,a,b)for(ll i=(a);i<=(b);i++)
#define repR(i,n) for(ll i=n;i>=0;i--)
#define all(v)(v).begin(),(v).end()
#define rall(v)(v).rbegin(),(v).rend()
#define F first
#define S second
#define pb push_back
#define pu push
#define COUT(x) cout<<(x)<<"\n"
#define PQ priority_queue<ll>
#define PQR priority_queue<ll,vector<ll>,greater<ll>>
#define YES(n) cout << ((n) ? "YES\n" : "NO\n"  )
#define Yes(n) cout << ((n) ? "Yes\n" : "No\n"  )
#define mp make_pair
#define sz(x) (ll)(x).size()
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 1000000007LL;
const ll INF = 1LL << 60;
using vll = vector<ll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvll = vector<vll>;
using vstr = vector<string>;
using vc = vector<char>;
using vvc = vector<vc>;
template<class T> inline bool chmax(T& a, T b) { 
 if (a < b) { a = b; return true; } return false; 
}
template<class T> inline bool chmin(T& a, T b) {
 if (a > b) { a = b; return true; } return false; 
}
ll dx[4]={0,1,0,-1};
ll dy[4]={1,0,-1,0};

struct edge{ll from,to,cost;};

void bfs(ll s,vvll tt,vb &ch,ll n){
  vb gg(n,false);
  gg[s]=true;
  queue<ll> que;
  que.pu(s);
  while(sz(que)){
    ll now=que.front();
    que.pop();
    for(auto p:tt[now]){
      if(gg[p]) continue;
      gg[p]=true;
      que.pu(p);
    }
  }
  rep(i,n){
    ch[i]=gg[i]&ch[i];
  }
}
void rbfs(ll s,vvll ttt,vb &ch,ll n){
  vb gg(n,false);
  gg[s]=true;
  queue<ll> que;
  que.pu(s);
  while(sz(que)){
    ll now=que.front();
    que.pop();
    for(auto p:ttt[now]){
      if(gg[p]) continue;
      gg[p]=true;
      que.pu(p);
    }
  }
  rep(i,n){
    ch[i]=gg[i]&ch[i];
  }
}
int main(){
  ll n,m;cin>>n>>m;
  vector<edge> t(m);
  vvll tt(n,vll(0));
  vvll ttt(n,vll(0));
  vb ch(n,true);
  rep(i,m){
    ll a,b,c;
    cin>>a>>b>>c;
    a--;b--;
    tt[a].pb(b);
    ttt[b].pb(a);
    edge e;
    e.from=a;
    e.to=b;
    e.cost=-1*c;
    t[i]=e;
  }
  bfs(0,tt,ch,n);
  rbfs(n-1,ttt,ch,n);
  vll d(n,INF);
  d[0]=0;
  ll cu=0;
  while(1){
    bool up=false;
    rep(i,m){
      edge e=t[i];
      if(ch[e.from]&&ch[e.to]&&d[e.from]!=INF&&d[e.to]>d[e.from]+e.cost){
        d[e.to]=d[e.from]+e.cost;
        up=true;
        if(cu==n-1){
          COUT("inf");
          return 0;
        }
      }
    }
    
    cu++;
    if(!up) break;
  }
  COUT(-1*d[n-1]);
}