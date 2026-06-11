#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int a, b, c;
  cin >> a >> b >> c;
  cout << ((2 * b) == (a + c) ? "YES" : "NO") << "\n";
  return 0;
}
