#include <iostream>
#include <algorithm>

using namespace std;

int const NMAX = 100;
int v[1 + NMAX + 1];

int main() {

  long long a, b, c;
  cin >> a >> b >> c;
  cout << min(abs(((a / 2) + a % 2) * (b * c) - ((a / 2)) * (b * c) ),min(abs(((b / 2) + b % 2) * (a * c) - ((b / 2)) * (a * c) ), abs(((c / 2) + c % 2) * (b * a) - ((c / 2)) * (b * a) )));
  return 0;
}
