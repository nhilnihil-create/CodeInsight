#include <bits/stdc++.h>
using namespace std;
#define rep(i, seisu) for(int i = 0; i < (int)(seisu); i++)
typedef long long ll;


int main(){
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a.at(i);
  sort(a.begin(), a.end());
  
  ll ans = 0, same;
  ll i = 0;
  while(i < n){
    same = 0;
    ll k = 1;
    while(i + k < n && a.at(i+k) - a.at(i) == 0){
      same++;
      k++;
    }
    if (same%2 == 0){
      ans++;
    } 

    
    
    i += k;
    
  }
  cout << ans << endl;

}
