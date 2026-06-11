#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  string a, b, c;
  cin >> a >> b >> c;
  char t = 'a';
  for (int i = 0;; i++) {
    if (t == 'a') {
      if(a.size() == 0) break;
      t = a[0];
      a = a.substr(1);
    } else if (t == 'b') {
      if(b.size() == 0) break;
      t = b[0];
      b = b.substr(1);
    } else if (t == 'c') {
      if(c.size() == 0) break;
      t = c[0];
      c = c.substr(1);
    }
  }
  cout << char(t - 32) << endl;
  return 0;
}