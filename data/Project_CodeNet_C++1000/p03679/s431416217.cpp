#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main(void) {
  int x, a, b;
  cin >> x >> a >> b;

  if (a >= b) {
    cout << "delicious" << endl;
    return 0;
  }

  if (a + x >= b) {
    cout << "safe" << endl;
    return 0;
  }

  cout << "dangerous" << endl;
  
  return 0;
}