#include <iostream>
using namespace std;
int main() {
  long long t, a, T{1}, A{1}, k;
  cin >> k;
  while (cin >> t >> a) {
    k = max((A - 1) / a, (T - 1) / t) + 1;
    A = k * a, T = k * t;
  }
  cout << T + A << endl;
}
