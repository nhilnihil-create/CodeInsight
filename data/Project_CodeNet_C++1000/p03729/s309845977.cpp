#include <bits/stdc++.h>
using namespace std;

int main() {
  string a, b, c;
  cin >> a >> b >> c;
  reverse(a.begin(), a.end());
  if (a.at(0) == b.at(0)) {
    reverse(b.begin(), b.end());
    if (b.at(0) == c.at(0)) {
      cout << "YES" << endl;
    }
    else cout << "NO" << endl;
  }
  else cout << "NO" << endl;
}