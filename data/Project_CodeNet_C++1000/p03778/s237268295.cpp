#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
ll euclidean_gcd(ll a, ll b) {
  while(1) {
    if(a < b) swap(a, b);
    if(!b) break;
    a %= b;
  }
  return a;
}


int main() {
  int w, a, b;
  cin >> w >> a >> b;
  int ans = max(0,abs(b-a)-w);
  cout << ans << endl;
  return 0;
}