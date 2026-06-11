#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  ll A,B,C;
  cin >> A >> B >> C;
  if (A%2 != 0 || B%2 != 0 || C%2 != 0) {
    cout << 0 << endl;
    return 0;
  }
  if (A==B&&B==C) {
    cout << -1 << endl;
    return 0;
  }
  ll ans = 0;
  while (A % 2 == 0 && B % 2 == 0 && C % 2 == 0) {
    ll Ar = A;
    ll Br = B;
    ll Cr = C;
    A = (Br/2) + (Cr/2);
    B = (Cr/2) + (Ar/2);
    C = (Ar/2) + (Br/2);
    ans++;
  }
  cout << ans << endl;
  return 0;
}
