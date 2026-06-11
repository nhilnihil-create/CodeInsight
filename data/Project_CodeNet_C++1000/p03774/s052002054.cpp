#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll kyori(ll x,ll y,ll nx,ll ny){
  ll a=0;
  a+=max(x-nx,nx-x);
  a+=max(y-ny,ny-y);
  return(a);
}

int main(){
  int n,m;
  cin >> n >> m;
  vector<pair<ll,ll>> s(n);
  for(int i=0;i<n;i++) cin >> s.at(i).first >> s.at(i).second;
  vector<pair<ll,ll>> p(m);
  for(int i=0;i<m;i++) cin >> p.at(i).first >> p.at(i).second;
  
  for(int i=0;i<n;i++){
    ll ans=1;
    ll k=kyori(s.at(i).first,s.at(i).second,p.at(0).first,p.at(0).second);
    for(int j=1;j<m;j++){
      if(kyori(s.at(i).first,s.at(i).second,p.at(j).first,p.at(j).second)<k){
        ans=j+1;
        k=kyori(s.at(i).first,s.at(i).second,p.at(j).first,p.at(j).second);
      }
    }
    cout << ans << endl;
  }
}