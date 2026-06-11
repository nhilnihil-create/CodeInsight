#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if (a == b && b == c && a % 2 == 0) {
    cout << -1 << endl;
    return 0;
  }
  int ans = 0;
  while (a % 2 == 0 && b % 2 == 0 && c % 2 == 0) {
    int na = b / 2 + c / 2;
    int nb = c / 2 + a / 2;
    int nc = a / 2 + b / 2;
    a = na;
    b = nb;
    c = nc;
    ans++;
  }
  cout << ans << endl;
  return 0;
}