#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  ll sum = a;
  for (int i = 0; i < 1000; i++) {
    if (sum % b == c) {
      cout << "YES" << endl;
      return 0;
    }
    sum += a;
  }
  cout << "NO" << endl;
  return 0;
}