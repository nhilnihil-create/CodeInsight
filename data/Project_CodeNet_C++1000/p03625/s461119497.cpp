#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
using ll = long long;
using P = pair<ll,ll>;

int main(){
  ll n;cin>>n;
  vector<ll> v(n);
  rep(i,n) cin>>v.at(i);
  sort(v.begin(),v.end());
  reverse(v.begin(),v.end());
  ll tate = 0,yoko = 0;
  rep(i,n-1){
    if (v.at(i) == v.at(i+1)){
      tate=max(tate,v.at(i));
      i++;
    }
    if (tate > 0 && yoko >0){
      cout << tate * yoko << endl;
      return 0;
    }
    if (tate>0){
      yoko = tate;
      tate = 0;
    }
  }
  cout << 0 << endl;
}