#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 1; i <= (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  ll ans = 1;
  rep (i, n){
    ans *= i;
    ans = ans % (1000000007);
  }
  cout << ans << endl;
  return 0;
}