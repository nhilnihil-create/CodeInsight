#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  ll a,b,x;
  cin >> a >> b >> x;
  ll ans;
  if (a == 0 && b == 0) {
    ans = 1; 
  } else if (a == 0){
    ans = b/x + 1;
  } else {
    ans = b/x - (a-1)/x;
  }
  cout << ans << endl;
  return 0;
}