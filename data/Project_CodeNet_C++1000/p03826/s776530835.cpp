#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a,b,c,d;
  cin >> a >> b >> c >> d;
  int ans = max(a*b, c*d);

  cout << ans << endl;
  return 0;
}
