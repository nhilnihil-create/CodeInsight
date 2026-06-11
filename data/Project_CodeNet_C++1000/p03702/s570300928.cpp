//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const long long INF= 1e+18+1;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const ll MOD=1000000007LL;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main(){
  ll n,a,b;cin>>n>>a>>b;
  vl h(n);
  rep(i,n)cin>>h[i];
  ll ng=0,ok=1e9;
  while(ok-ng>1){
    ll md=(ok+ng)/2;
    ll cnt=0;
    rep(i,n){
      cnt+=(max(0LL,h[i]-md*b)+(a-b)-1)/(a-b);
    }
    if(cnt<=md)ok=md;else ng=md;
  }
  cout<<ok<<endl;
}
  