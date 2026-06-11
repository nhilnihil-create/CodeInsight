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
  sort(a.begin(),a.end());
  vl sum(n);
  sum[0]=a[0];
  for(ll i=1;i<n;i++)sum[i]=sum[i-1]+a[i];
  ll count=1;
  for(ll i=n-2;i>=0;i--){
    if(2*sum[i]>=a[i+1])count++;
    else break;
  }
  cout<<count<<endl;
}
  