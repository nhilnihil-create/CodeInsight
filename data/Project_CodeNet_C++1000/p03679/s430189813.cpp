#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, a, b;
  cin >> x >> a >> b;
  int tmp = b - a;
  if (tmp <= 0) return cout << "delicious" << "\n", 0; 
  if (tmp <= x) return cout << "safe" << "\n", 0;
  cout << "dangerous" << "\n";
}