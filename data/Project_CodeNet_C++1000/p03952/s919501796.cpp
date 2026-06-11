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
  ll n,x;
  cin>>n>>x;
  if(x==1||x==2*n-1){
    COUT("No");
  }
  else if(n==2){
    COUT("Yes");
    COUT(1);
    COUT(2);
    COUT(3);
  }
  else{
    vll a(4);
    set<ll> s;
    rep(i,2*n-1){
        s.insert(i+1);
    }
    a[1]=x;
    if(x==2){
      a[0]=3;
      a[2]=1;
      a[3]=4;
      
    }
    else if(x==2*n-2){
      a[2]=2*n-1;
      a[0]=2*n-3;
      a[3]=2*n-4;
    }
    else{
      a[0]=x-1;
      a[2]=x+1;
      a[3]=x-2;
    }
    rep(i,sz(a)){
      s.erase(a[i]);
    }
    
    COUT("Yes");
    rep(i,(2*n-1)/2-1){
      COUT(*begin(s));
      ll h=*begin(s);
      s.erase(h);
    }
    rep(i,4){
      COUT(a[i]);
    }
    for(auto p:s){
      COUT(p);
    }
  }
}