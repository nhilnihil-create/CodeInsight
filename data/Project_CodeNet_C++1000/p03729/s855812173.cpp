#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string a, b, c;
  cin >> a >> b >> c;
  if ((a[a.length() - 1] == b[0]) && (b[b.length() - 1] == c[0]))
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
