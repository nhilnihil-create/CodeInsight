#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
  ll a, b, x;
  cin >> a >> b >> x;
  
  ll ans_a = (a-1)/x + 1;
  ll ans_b = b/x + 1;
  if (a == 0) ans_a = 0;
  if (b == 0) ans_b = 1;
  cout << ans_b - ans_a << endl;
  return 0;
}