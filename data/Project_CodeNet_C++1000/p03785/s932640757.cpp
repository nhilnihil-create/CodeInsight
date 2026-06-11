//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define bit(n,k) (((ll)n>>(ll)k)&1) /*nのk bit目*/
const long long INF= 1e+18+1;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const ll MOD=1000000007LL;
//const ll MOD=998244353LL;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
vl dx={-1,-1,-1,0,0,1,1,1};
vl dy={1,-1,0,1,-1,1,0,-1};
ll modpow(ll a, ll n, ll mod) {
  
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
ll factorial(ll x){
  if(x==0)return 1;
  return x*factorial(x-1)%MOD;
}
int main(){
  ll n;cin>>n;
  ll c,k;cin>>c>>k;
  vl t(n);
  rep(i,n)cin>>t[i];
  sort(t.begin(),t.end());
  ll count=0;
  ll bus=0;
  while(count<n){
    ll now=count;
    while(t[count]<=t[now]+k&&count-now+1<=c&&count<n){
      count++;
    }
    bus++;
  }  

  cout<<bus<<endl;
}