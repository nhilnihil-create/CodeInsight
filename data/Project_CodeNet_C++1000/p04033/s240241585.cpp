#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  int a, b;
  cin >> a >> b;
  if ((a <= 0 && 0 <= b) || a == 0 || b == 0) {
    cout << "Zero" << endl;
  } else if ((0 < a) || (b - a + 1) % 2 == 0) {
    cout << "Positive" << endl;
  } else {
    cout << "Negative" << endl;
  }
  return 0;
}