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

  if (abs(x - a) < abs(x - b)) {
    cout << "A" << endl;
  } else {
    cout << "B" << endl;
  }
  
  return 0;
}