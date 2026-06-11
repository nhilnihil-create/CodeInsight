#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll X, Y;

int main() {
  cin >> X >> Y;
  cout << (abs(X - Y) >= 2 ? "Alice" : "Brown") << endl;
  return 0;
}
