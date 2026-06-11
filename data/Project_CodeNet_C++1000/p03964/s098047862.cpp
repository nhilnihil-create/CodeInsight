#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
  ll t, a, T{1}, A{1}, k;
  cin >> k;
  while(cin >> t >> a) {
    k = ((ld)T/A < (ld)t/a ? (A-1)/a+1 : (T-1)/t+1);
    A = k * a, T = k * t;
  }
  cout << T + A << endl;
}
