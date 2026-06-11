#include <iostream>

using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if ((c - b) == (b - a)) cout << "YES";
  else cout << "NO";
  cout << '\n';
  return 0;
}