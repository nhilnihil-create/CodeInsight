#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  ll sum = 0;
  int sign = 1;
  ll count = 0;
  ll ans = LLONG_MAX;
  // if 0   +1
  rep(j, 2){
    if (j == 0) sign = 1;
    else sign = -1;
    sum = 0;
    count = 0;
    rep(i, n){
      sum += a[i];
      if ((sign > 0) && (sum <= 0)){
        count += (1 - sum);
        sum = 1;
      } else if ((sign < 0) && (sum >= 0)){
        count += abs(-1 - sum);
        sum = -1;
      }
      sign = sign == 1 ? -1 : 1;
    }
    if (ans > count) ans = count;
  }
  cout << ans << endl;
  return 0;
}