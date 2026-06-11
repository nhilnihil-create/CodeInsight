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
  string a;cin>>a;
  ll n=a.size();
  ll ans=1+n*(n-1)/2;
  map<char,ll>M;
  rep(i,n)M[a[i]]++;
  for(auto p:M){
    ans-=p.second*(p.second-1)/2;
  }
  cout<<ans<<endl;
}