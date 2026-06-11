#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  cout << (max(n%10, n/10)==9 ? "Yes" : "No") << '\n';
}