#include <iostream>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  if (n == 1) n = 14;
  if (m == 1) m = 14;
  if (n > m) cout << "Alice\n";
  else if (n < m) cout << "Bob\n";
  else cout << "Draw\n";
  return 0;
}
