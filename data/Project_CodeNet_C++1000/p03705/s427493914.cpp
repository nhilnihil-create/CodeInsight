#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll n, a, b;
  cin >> n >> a >> b;

  if (a > b)
    cout << 0 << endl;
  else if (n == 1 && a != b)
    cout << 0 << endl;
  else if (n == 1 && a == b)
    cout << 1 << endl;
  else {
    cout << (n - 2) * (b - a) + 1 << endl;
  }
}