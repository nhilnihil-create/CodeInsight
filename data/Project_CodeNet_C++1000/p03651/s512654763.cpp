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
  ll n,k;
  cin>>n>>k;
  vl a(n);
  rep(i,n)cin>>a[i];
  ll g=0;
  ll MAX=0;
  rep(i,n){
    MAX=max(MAX,a[i]);
    g=__gcd(g,a[i]);
  }
  if(k<=MAX&&k%g==0){
    cout<<"POSSIBLE"<<endl;
  }
  else {
    cout<<"IMPOSSIBLE"<<endl;
  }
}