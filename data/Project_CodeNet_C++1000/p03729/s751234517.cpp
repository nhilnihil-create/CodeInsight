#include <iostream>
#include <string>

using namespace std;

int main() {
  string a, b, c;
  cin >> a >> b >> c;
  size_t as = a.size();
  size_t bs = b.size();
  if (a[as - 1] == b[0] && b[bs - 1] == c[0]) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
