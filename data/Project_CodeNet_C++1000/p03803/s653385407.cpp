#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main(void) {
  int a, b;
  cin >> a >> b;

  a = a == 1 ? 14 : a;
  b = b == 1 ? 14 : b;
  if (a > b) {
    cout << "Alice" << endl;
  } else if (a < b) {
    cout << "Bob" << endl;
  } else {
    cout << "Draw" << endl;
  }
  
  return 0;
}