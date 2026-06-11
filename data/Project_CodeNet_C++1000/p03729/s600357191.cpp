#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main(void) {
  string a, b, c;
  cin >> a >> b >> c;
  if (a.back() == b.front() && b.back() == c.front()) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  
  return 0;
}