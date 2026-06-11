#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main() {
  int x, a, b;
  cin >> x >> a >> b;
  if (b <= a) {
    cout << "delicious";
  } else if (b > a && b <= a+x) {
    cout << "safe";
  } else {
    cout << "dangerous";
  }
  return 0;
}
