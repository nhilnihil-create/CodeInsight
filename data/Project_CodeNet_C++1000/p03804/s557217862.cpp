#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)


int main() {
  ll n,m;cin >> n >> m;
  vector<string> a(n),b(m);
  rep(i,n) cin >> a.at(i);
  rep(i,m) cin >> b.at(i);


  for(ll i=0;i<=n-m;++i){//上からのズレ
    for(ll j=0;j<=n-m;++j){//左端からのズレ
      bool ok = true;
      rep(k,m){
        if( b.at(k) != a.at(i+k).substr(j,m) ){
          ok = false;
          break;
        }
      }
      if( ok ){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}