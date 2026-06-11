#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int a, b;
  char ch;
  cin >> a >> ch >> b;
  if (ch == '+')
    cout << a + b << "\n";
  else
    cout << a - b << "\n";
  return 0;
}
