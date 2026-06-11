#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if (a == b && b == c && a % 2 == 0) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 0;; i++) {
    if (a % 2 == 1 || b % 2 == 1 || c % 2 == 1) {
      cout << i << endl;
      break;
    }
    int p_a = a;
    int p_b = b;
    int p_c = c;
    a = p_b / 2 + p_c / 2;
    b = p_a / 2 + p_c / 2;
    c = p_a / 2 + p_b / 2;
  }
  return 0;
}