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
  vl a(n),b(n);
  rep(i,n)cin>>a[i]>>b[i];
  reverse(a.begin(),a.end());
  reverse(b.begin(),b.end());
  ll count=0;
  rep(i,n){
    count+=((a[i]+count)+b[i]-1)/b[i]*b[i]-(a[i]+count);
  }
  cout<<count<<endl;
}