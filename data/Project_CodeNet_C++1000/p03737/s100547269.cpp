#include <bits/stdc++.h>
using namespace std;

int main() {
  string a, b, c;
  locale l = locale::classic();
  cin >> a >> b >> c;
  cout << toupper(a[0], l) << toupper(b[0], l) << toupper(c[0], l) << "\n";

  return(0);
}
