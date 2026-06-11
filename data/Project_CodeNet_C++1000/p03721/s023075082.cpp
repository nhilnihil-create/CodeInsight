#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll n,k;
  cin >> n >> k;
  vector<pair<ll,ll>> pa(n);
  rep(i,n){
    ll a,b;
    cin >> a >> b;
    pa.at(i)=make_pair(a,b);
  }
  sort(pa.begin(),pa.end());
  ll ans=0,sum=0;
  rep(i,n){
    sum+=pa.at(i).second;
    if(sum>=k){
      ans=pa.at(i).first;
      break;
    }
  }
  cout << ans;
}