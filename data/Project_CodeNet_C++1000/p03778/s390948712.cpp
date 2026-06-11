#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  int w, a, b;
  cin >> w >> a >> b;
  if (abs(a - b) <= w) {
    cout << 0 << endl;
    return 0;
  }
  cout << min(abs(a + w - b), abs(b + w - a)) << endl;
  return 0;
}