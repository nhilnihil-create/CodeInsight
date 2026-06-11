#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 1; i <= (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
  ll n;
  cin >> n;
  int ans = 20;
  int until = sqrt(n);
  rep(i,until){
    if (n % i == 0){
      int b = n / i;
      int f = 0;
      while (b != 0){
        ++f;
        b /= 10;
      }
      if (ans > f) ans = f;
    }
  }
  cout << ans << endl;
  return 0;
}