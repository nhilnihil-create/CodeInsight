#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int a, b;
  cin >> a >> b;
  if (a + b >= 10)
    cout << "error\n";
  else
    cout << a + b << "\n";
  return 0;
}
