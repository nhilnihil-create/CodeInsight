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
  ll n,ans=1;
  cin>>n;
  ll a=1,b=1;
  rep(i,n){
    ll c,d;cin>>c>>d;
    ll g=max({(a+c-1)/c,(b+d-1)/d,(a+b+c+d-1)/(c+d)});
    a=c*g;b=d*g;
  }
  cout<<a+b<<endl;
}