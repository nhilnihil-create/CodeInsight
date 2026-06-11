//#define _GLIBCXX_DEBUG

#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const int INF= 1e9+5;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const ll MOD=1000000007LL;
int main(){
  ll n;cin>>n;
  vl a(n);
  rep(i,n)cin>>a[i];
  map<ll,ll>M;
  rep(i,n){
    if(a[i]%4==0)M[4]++;
    else if(a[i]%2==0)M[2]++;
    else M[1]++;
  }
  if(M[2]==n || M[4]==n/2 ||M[2]>=n-2*M[4]){
    cout<<"Yes"<<endl;
  }
  else cout<<"No"<<endl;
}