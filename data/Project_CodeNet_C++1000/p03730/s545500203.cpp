#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main(void) {
  int a, b, c;
  cin >> a >> b >> c;

  for (ll i = 1; i < 100000; i++) {
    if ((a * i) % b == c) {
      cout << "YES" << endl;
      return 0;
    }
  }

  cout << "NO" << endl;
  
  return 0;
}