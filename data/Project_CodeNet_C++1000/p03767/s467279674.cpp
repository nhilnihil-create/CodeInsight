#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  vector<int> v(3 * n);
  rep(i, 3*n) cin >> v[i];

  sort(v.begin(), v.end());
  v.erase(v.begin(), v.begin() + n);
  ll ans = 0;
  rep(i, 2*n){
    if ((i % 2) == 0) ans += v[i];
  }
  cout << ans << endl;
  return 0;
}