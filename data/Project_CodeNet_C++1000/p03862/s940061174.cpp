#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  ll x;
  cin >> n >> x;
  ll a[n];
  rep(i, n) cin >> a[i];
  
  // int sum[n-1];
  // rep(i, n-1) sum[i] = a[i] + a[i+1];
  ll b[n];
  rep(i, n) b[i] = a[i];
  
  ll res = 0;
  rep(i, n-1){
    if(b[i] + a[i+1] > x){
      ll dif = (b[i] + a[i+1] - x);
      if(dif > a[i+1]){
        b[i] -= (dif - a[i+1]);
        b[i+1] = 0;
      }else{
        b[i+1] -= dif;
      }
    }
  }

  rep(i, n){
    res += (a[i] - b[i]);
  }
  
  cout << res << endl;
  
  return 0;
}