#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll a[8];

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  
  for (int i = 0; i < 7; i++) {
    cin >> a[i];
  }  
  ll tmp = 0;
  tmp += (a[0]/2)*4;
  tmp += (a[3]/2)*4;
  tmp += (a[4]/2)*4;

  if (a[0] && a[3] && a[4]) {
    ll tmp2 = 6;
    tmp2 += ((a[0]-1)/2)*4;
    tmp2 += ((a[3]-1)/2)*4;
    tmp2 += ((a[4]-1)/2)*4;
    tmp = max(tmp, tmp2);
  }
  
  ll ans = a[1]*2 + tmp;
  cout << ans/2 << endl;

  return 0;
}