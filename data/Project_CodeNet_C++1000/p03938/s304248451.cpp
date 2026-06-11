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

int main(){
  ll n;cin>>n;
  vl p(n+1);
  rep(i,n)cin>>p[i+1];
  vl q(n+1);
  for(ll i=1;i<=n;i++)q[p[i]]=i;
  vl a(n+1),b(n+1);
  a[1]=1;
  b[1]=1000000000LL;
  for(ll i=2;i<=n;i++){
    a[i]=a[i-1]+1;
    b[i]=b[i-1]-1;
    ll d=q[i]-q[i-1];
    if(d>0)a[i]+=d;
    else b[i]+=d;
  }
  for(ll i=1;i<=n;i++){
    cout<<a[i];
    if(i!=n)cout<<" ";
    else cout<<endl;
  }
  for(ll i=1;i<=n;i++){
    cout<<b[i];
    if(i!=n)cout<<" ";
    else cout<<endl;
  }
}