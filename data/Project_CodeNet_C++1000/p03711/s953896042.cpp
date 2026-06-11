#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int store[] = {0, 1, 3, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1};
  int x, y;
  cin >> x >> y;
  cout << ((store[x] == store[y]) ? "Yes\n" : "No\n") << "\n";
  return 0;
}
