#include <iostream>

using namespace std;

int main() {
  int x, y;
  int d[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  cin >> x >> y;
  cout << ((d[x - 1] == d[y - 1]) ? "Yes" : "No") << endl;
  return 0;
}
