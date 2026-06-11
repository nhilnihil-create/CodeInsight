#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n){
    cin >> a.at(i);
  }
  ll ans=-1,v=1;
  rep(i,n){
    v=a.at(v-1);
    if(v==2){
      cout << i+1;
      return 0;
    }
  }
  cout << ans;
}
  
    