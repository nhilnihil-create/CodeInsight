#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int a, b;
  cin >> a >> b;
  if (b < 0 && (b-a+1)%2 == 1) cout << "Negative";
  else if (a <= 0 && b >= 0) cout << "Zero";
  else cout << "Positive";
}
