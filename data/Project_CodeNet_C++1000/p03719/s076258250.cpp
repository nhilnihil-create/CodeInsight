#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int a, b, c;
  cin >> a >> b >> c;
  if (c >= a && c <= b)
    cout << "Yes\n";
  else
    cout << "No\n";
  return 0;
}
