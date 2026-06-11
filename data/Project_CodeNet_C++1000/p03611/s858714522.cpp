#include <bits/stdc++.h>
using namespace std;
#define rep(i, seisu) for(int i = 0; i < (int)(seisu); i++)
typedef long long ll;


int main() {
  ll n;
  cin >> n;
  ll a[n];
  rep(i, n) cin >> a[i];
  
  int m = 100010;
  
  
  ll check[m];
  rep(i, m) {
    check[i] = 0;
  }

  rep(i, n){
     check[a[i]] ++;
   }
   
  ll ans = 0;

  rep(i, m-2){
    ll sum = 0;
    sum = check[i] + check[i+1] + check[i+2];

    if (sum > ans) ans = sum;
  }
  cout << ans << endl;
}