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
int main(){
  ll n,ma,mb;
  cin>>n>>ma>>mb;
  vll a(n),b(n),c(n);
  rep(i,n){
    cin>>a[i]>>b[i]>>c[i];
  }
  map<pll,ll> x,y;
  for(int bit=0;bit<(1<<(n/2));bit++){
    pll p=pll(0,0);
    ll cost=0;
    rep(i,n/2){
      if(bit&(1LL<<i)){
        p.F+=a[i];
        p.S+=b[i];
        cost+=c[i];
      }
    }
    if(x.count(p)){
      chmin(x[p],cost);
    }
    else x[p]=cost;
  }
  for(int bit=0;bit<(1<<(n-n/2));bit++){
    pll p=pll(0,0);
    ll cost=0;
    rep(i,n-n/2){
      if(bit&(1LL<<i)){
        p.F+=a[i+n/2];
        p.S+=b[i+n/2];
        cost+=c[i+n/2];
      }
    }
    if(y.count(p)){
      chmin(y[p],cost);
    }
    else y[p]=cost;
  }
  ll ans=INF;
  for(auto p:x){
    pll now=p.F;
    for(int i=1;i<=40;i++){
      ll mma=ma*i;
      ll mmb=mb*i;
      if(y.count(pll(mma-now.F,mmb-now.S))){
        chmin(ans,p.S+y[pll(mma-now.F,mmb-now.S)]);
      }
    }
  }
  if(ans==INF) COUT(-1);
  else COUT(ans);
}
      