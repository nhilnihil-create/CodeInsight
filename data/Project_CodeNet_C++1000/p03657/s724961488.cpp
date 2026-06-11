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

  if (a % 3 == 0 ||
      b % 3 == 0 ||
      (a + b) % 3 == 0) {
    cout << "Possible" << endl;
  } else {
    cout << "Impossible" << endl;
  }
  
  return 0;
}