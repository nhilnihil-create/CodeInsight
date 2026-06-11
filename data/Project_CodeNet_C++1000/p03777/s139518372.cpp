#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main(void) {
  char a, b;
  cin >> a >> b;

  if (a == 'H') {
    cout << b << endl;
  } else {
    if (b == 'H') {
      cout << 'D' << endl;
    } else {
      cout << 'H' << endl;
    }
  }
  
  return 0;
}