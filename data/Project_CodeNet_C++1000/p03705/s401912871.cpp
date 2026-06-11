#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;

int main() {
  ll n, a, b;
  cin >> n >> a >> b;
  if (n == 1) {
    if (a == b) cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
  }
  if (b < a) {
    cout << 0 << endl;
    return 0;
  }
  cout << (b - a) * (n - 2) + 1 << endl;
  return 0;
} 