#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll a,b;
  cin >> a >> b;
  if (a <= 0 && 0 <= b) {
    cout << "Zero" << endl;
  }
  else if (a > 0 && b > 0) {
    cout << "Positive" << endl;
  }
  else if ((b - a) % 2 == 0) {
    cout << "Negative" << endl;
  }
  else {
    cout << "Positive" << endl;
  }
  return 0;
}