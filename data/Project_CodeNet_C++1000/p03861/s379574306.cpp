#include <iostream>

using namespace std;
using ll = long long;

int main() {
  ll a, b, x;
  cin >> a >> b >> x;
  if (a != 0)
    cout << b / x - (a - 1) / x << endl;
  else
    cout << b / x + 1 << endl;
  
}
