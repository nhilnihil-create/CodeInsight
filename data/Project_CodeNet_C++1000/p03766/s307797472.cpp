#include <bits/stdc++.h>
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep3(i,a,b) for(ll i=a;i>=b;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define vec vector<int>
#define vecll vector<ll>
#define vecpii vector<pii>
#define vec2(a,b) vector<vec>(a,vec(b))
#define vec2ll(a,b) vector<vec>(a,vecll(b))
#define vec3(a,b,c) vector<vector<vec>>(a,vec2(b,c))
#define vec3ll(a,b,c) vector<vector<vecll>>(a,vec2ll(b,c))
#define fi first
#define se second
#define endl "\n"
#define all(c) begin(c),end(c)
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),x))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),x))
#define MM " "
using namespace std;
int in() {int x;cin>>x;return x;}
ll lin() {ll x;cin>>x;return x;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline void print(pair<T,T> p){cout<<"("<<p.first<<","<<p.second<<") ";}
template<class T> inline void print(vector<pair<T,T>> v){for(auto e:v)print(e); cout<<endl;}
template<class T> inline void print(T v){for(auto e:v)cout<<e<<" ";cout<<endl;}
const ll mod=1e9+7;
ll dp[3100000];
main(){
  int n=in();
  ll ans=0;
  dp[1]=1;
  dp[2]=mod-1;
  rep2(i,1,n){
  dp[i]=(dp[i]%mod+mod)%mod;
  dp[i]=(dp[i]+dp[i-1])%mod;
  ans+=(n-1)*dp[i]%mod;
  if(i==n){ans+=dp[i];break;}
  ans+=dp[i]*(n-1)%mod*(n-2)%mod;
  ans%=mod;
  dp[i+1]+=dp[i];
  dp[i+2]-=dp[i];
  dp[i+3]+=dp[i];
  dp[i+n+2]-=dp[i];
  }
  rep2(i,n+1,n*3){
  dp[i]=(dp[i]%mod+dp[i-1]+mod)%mod;
  ans=(ans+dp[i])%mod;}
  cout<<ans<<endl;
}
