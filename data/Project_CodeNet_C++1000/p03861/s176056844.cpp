#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  ll a, b, x;
  cin >> a >> b >> x;
  ll ans = b/x-(a+x-1)/x+1;
  cout << ans << endl;
  return 0;
}