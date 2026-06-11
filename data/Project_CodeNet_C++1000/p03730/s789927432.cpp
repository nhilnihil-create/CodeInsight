#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  // a * x % b == c % b
  // a * x ≡ c mod b
  if (__gcd(b, c) % __gcd(a, b))
    cout << "NO";
  else
    cout << "YES";
  return 0;
}
