#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  string st;
  cin >> st;
  bool n, e, w, s;
  n = e = w = s = false;
  for (int i = 0; i < st.size(); i++) {
    switch (st[i]) {
      case 'N':
        n = true;
        break;
      case 'E':
        e = true;
        break;
      case 'W':
        w = true;
        break;
      case 'S':
        s = true;
        break;
    }
  }
  if (n == s && w == e) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}