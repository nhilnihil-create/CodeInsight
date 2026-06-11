#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
  ll a, b;
  cin >> a >> b;
  cout << ((abs(a - b) >= 2) ? "Alice" : "Brown") << endl;
}
