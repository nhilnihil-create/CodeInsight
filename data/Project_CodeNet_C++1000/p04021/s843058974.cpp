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
  ll n;cin>>n;
  vl a(n);
  rep(i,n)cin>>a[i];
  vl b=a;
  sort(b.begin(),b.end());
  map<ll,ll>M;
  rep(i,n)M[b[i]]=i;
  ll ans=0;
  rep(i,n){
    ll d=abs(i-M[a[i]]);
    //cout<<d<<endl;
    if(d%2!=0)ans++;
  }
  cout<<ans/2<<endl;
}
  