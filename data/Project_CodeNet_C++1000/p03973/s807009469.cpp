#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n; cin >> n;
  ll ans = 0;
  int m = 1;
  for(int i = 0; i < n; i++) {
    int a; cin >> a;
    int b = (a + m - 1) / m - 1;
    ans += b;
    if(!b) m = max(m, a + 1);
    else m = max(m, 2);
  }
  cout << ans << endl;
}
