#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll n;
  cin >> n;
  ll power=1,mod=1e9+7;
  for(ll i=1;i<=n;i++){
    power*=i;
    power%=mod;
  }
  cout << power;
}
      