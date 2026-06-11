#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;

int main() {
  int n;
  cin >> n;
  ll m = pow(10,9) + 7;
  ll ans = 1;
  for(ll i = 1; i <= n; i++){
    ans = (ans*i)%m;
    
  }
  cout << ans << endl;
}
