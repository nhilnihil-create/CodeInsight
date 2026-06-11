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
  ll n,l;cin>>n>>l;
  vl a(n);
  rep(i,n)cin>>a[i];
  ll MAX=0;
  ll key=0;
  rep(i,n-1){
    if(MAX<a[i]+a[i+1]){
      MAX=a[i]+a[i+1];
      key=i+1;
    }
  }
  if(MAX<l){
    cout<<"Impossible"<<endl;
    return 0;
  }
  cout<<"Possible"<<endl;
  for(ll i=1;i<key;i++)cout<<i<<endl;
  for(ll i=n-1;i>key;i--)cout<<i<<endl;
  cout<<key<<endl;
}