#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main(void) {
  string a, b;
  cin >> a >> b;

  if (a.length() > b.length()) {
    cout << "GREATER" << endl;
  } else if (a.length() < b.length()) {
    cout << "LESS" << endl;
  } else if (a.length() == b.length()) {
    int i = 0;
    while (i < a.length()) {
      if (a[i] > b[i]) {
        cout << "GREATER" << endl;
        break;
      } else if (a[i] < b[i]) {
        cout << "LESS" << endl;
        break;
      }
      ++i;
    }
    if (i == a.length()) {
      cout << "EQUAL" << endl;
    }
  }
  
  return 0;
}